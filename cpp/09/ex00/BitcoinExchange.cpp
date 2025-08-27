#include "BitcoinExchange.hpp"

std::map<std::string, double> readData()
{
	std::map<std::string, double> _data;
	std::ifstream file("data.csv");
	if (!file)
		return _data;
	
	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, rate;
		if (std::getline(ss, date, ',') && std::getline(ss, rate))
			_data[date] = std::atof(rate.c_str()); //rate en double
	}
	return _data; //map remplie
}

void checkInput(const char *file, const std::map<std::string, double>& data)
{
	std::ifstream inputFile(file);
	if (!inputFile)
	{
		std::cerr << ERR_OPN_FILE << std::endl;
		return;
	}
	std::string firstLine;
	std::getline(inputFile, firstLine);
	if (firstLine != "date | value")
	{
		std::cerr << ERR_HEAD_FILE << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string date, value;
		
		if (!std::getline(iss, date, '|') || !std::getline(iss, value))
		{
			std::cerr << ERR_BAD_INPUT_PIPE << line << std::endl;
			continue;
		}

		date = trim(date);
		value = trim(value);

		if (!validDate(date) || !validValue(value))
		{
			std::cerr << ERR_BAD_DATE << date << std::endl;
			continue;
		}
		double val = std::atof(value.c_str());
		if (val < 0)
			std::cerr << ERR_NEG_NB << std::endl;
		else if (val > 1000)
			std::cerr << ERR_BIG_NB << std::endl;
		else
			std::cout << date << " => " << value << " = " << (val * findRate(date, data)) << std::endl;
	}
}

std::string dayBack(const std::string& date)
{
	int y, m, d;
	char dash1, dash2;
	std::istringstream ss(date);
	ss >> y >> dash1 >> m >> dash2 >> d;
	
	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return (ERR_DASH_DATE);
	d--;
	if (d == 0)
	{
		m--;
		if (m == 0)
		{
			m = 12;
			y--;
			if (y < 2009)
				return (ERR_DATE_YEAR);
		}
		static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		d = daysInMonth[m - 1];
		if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
			d = 29;
	}
	
	std::ostringstream formattedDate;
	formattedDate << y << "-" 
				  << (m < 10 ? "0" : "") << m << "-" 
				  << (d < 10 ? "0" : "") << d;
	return formattedDate.str();
}

bool validDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	
	int y, m, d;
	char dash1, dash2;
	std::istringstream ss(date);
	ss >> y >> dash1 >> m >> dash2 >> d;
	
	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return false;
	
	if (m < 1 || m > 12 || d < 1 || d > 31)
		return false;
	
	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));

	if (m == 2 && isLeap)
		return d <= 29;
	return d <= daysInMonth[m - 1];
}

bool validValue(const std::string& value)
{
	std::istringstream ss(value);  //idem lecture std::cin
	double val;
	ss >> val;
	return !ss.fail() && ss.eof(); //lire double
}

void printMap(const std::map<std::string, double>& map)
{
	for (std::map<std::string, double>::const_iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << "=" << it->second << " ";
	std::cout << std::endl;
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" ");
	size_t last = str.find_last_not_of(" ");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}

double findRate(const std::string& date, const std::map<std::string, double>& data)
{
	std::map<std::string, double>::const_iterator it = data.lower_bound(date);
	if (it == data.end() || (it != data.begin() && it->first != date))
		--it;
	if (it != data.end())
		return it->second;
	return 1998.0;
}
