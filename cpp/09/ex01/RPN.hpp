#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <stack>
#include <cctype>
#include <iostream>

#define BAD_INPUT "Mauvais nombre d'argument, Use :  ./RPN {RPN expression}"

class RPN
{
	private:
		std::stack<float> _data;
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN& other);

		void solveRPN(const char *expression);
		static int getOperatorType(int c);
		static bool checkWhiteSpace(char c);

	class InvalidSyntax : public std::exception 
	{
	public:
		const char* what() const throw()
		{
			return "Error: invalid syntax";
		}
	};

	class DivisionByZero : public std::exception 
	{
	public:
		const char* what() const throw() {
			return "Error: division by zero";
		}
	};
};

#endif