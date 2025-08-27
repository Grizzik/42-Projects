#include "iter.hpp"

int	main(void)
{
	int			arrayInt[5] = {0, 1, 2, 3, 5};
	float		arrayFloat[3] = {0.1, 1.56, 2.98};
	std::string	arrayStr[5] = {"Do", "Re", "Mi", "Fa", "Sol"};
	const char	*arrayStrC[5] = {"Mi", "Fa", "Do", "Re", "Sol"};
	char		arrayChar[5] = {'d', 'r', 'm', 'f', 's'};

	iter<int>(arrayInt, 5, printData);
	std::cout << std::endl;
	iter<int>(arrayInt, 2, printData);
	std::cout << std::endl;
	
	iter<float>(arrayFloat, 3, printData);
	std::cout << std::endl;
	iter<float>(arrayFloat, 2, printData);
	std::cout << std::endl;

	iter<std::string>(arrayStr, 5, printData);
	std::cout << std::endl;
	iter<std::string>(arrayStr, 3, printData);
	std::cout << std::endl;

	iter<const char *>(arrayStrC, 5, printData);
	std::cout << std::endl;
	iter<const char *>(arrayStrC, 4, printData);
	std::cout << std::endl;

	iter<char>(arrayChar, 5, printData);
	std::cout << std::endl;
	iter<char>(arrayChar, 2, printData);
	std::cout << std::endl;

	return (0);
}