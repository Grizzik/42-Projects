
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits.h>
# include <float.h>

class ScalarConverter
{
	private:
		ScalarConverter(void);

	public:

		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter(void);

		ScalarConverter	&operator = (ScalarConverter const &toCopy);

		static int		convert(std::string input);

		static void		printChar(std::string str);
		static void		printInt(std::string str);
		static void		printFloat(std::string str);
		static void		printDouble(std::string str);

};

#endif