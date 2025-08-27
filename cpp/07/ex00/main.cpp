#include "whatever.hpp"
#include <iostream>
#define YELLOW "\x1B[33m"
#define END "\033[0m"

int	main()
{
	{ //SUBJECT
	std::cout << std::endl << YELLOW << ">> subject" << END << std::endl;
		int a = 2;
		int b = 3;
	std::cout << "a = " << a << ", b = " << b <<  std::endl;
		::swap( a, b );
	std::cout << "a = " << a << ", b = " << b <<  std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{ //STRING
	std::cout << std::endl << YELLOW << ">> strings" << END << std::endl;
		std::string	a = "Coucou";
		std::string	b = "Hello";
	std::cout << "string a = " << a << ", string b = " << b << std::endl;
		::swap(a, b);
	std::cout << "string a = " << a << ", string b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "string min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "string max(a, b) = " << ::max(a, b) << std::endl;

	}
	{ //CHAR
	std::cout << std::endl << YELLOW << ">> char" << END << std::endl;
		char	a = 'a';
		char	b = 'z';
	std::cout << "char a = " << a << ", char b = " << b << std::endl;
		::swap(a, b);
	std::cout << "char a = " << a << ", char b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "char min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "char max(a, b) = " << ::max(a, b) << std::endl;
	}
	{ //DOUBLE
	std::cout << std::endl << YELLOW << ">> double" << END << std::endl;
		double	a = 1.6e21;
		double	b = 3.1e21;
	std::cout << "double a = " << a << ", double b = " << b << std::endl;
		::swap(a, b);
	std::cout << "double a = " << a << ", double b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "double min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "double max(a, b) = " << ::max(a, b) << std::endl;
	}
	return(0);
}
