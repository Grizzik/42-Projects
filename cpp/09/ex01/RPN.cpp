#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &) {}
RPN &RPN::operator=(const RPN &) { return *this; }

bool RPN::checkWhiteSpace(char c) { return (c >= 9 && c <= 13) || c == 32; }

int RPN::getOperatorType(int c)
{
	switch (c)
	{
		case '+': return 1;
		case '-': return 2;
		case '*': return 3;
		case '/': return 4;
		default: return 0;
	}
}

void RPN::solveRPN(const char *expression)
{
	std::string ex(expression);
	for (size_t i = 0; i < ex.size(); ++i)
	{
		if (std::isdigit(ex[i]))
		{
			_data.push(ex[i] - '0');
		}
		else if (getOperatorType(ex[i]))
		{
			if (_data.size() < 2) throw InvalidSyntax();
			
			float ope2 = _data.top(); _data.pop();
			float ope1 = _data.top(); _data.pop();
			
			switch (getOperatorType(ex[i])) {
				case 1: _data.push(ope1 + ope2); break;
				case 2: _data.push(ope1 - ope2); break;
				case 3: _data.push(ope1 * ope2); break;
				case 4: 
					if (ope2 == 0) throw DivisionByZero();
					_data.push(ope1 / ope2); 
					break;
			}
		}
		else if (!checkWhiteSpace(ex[i]))
		{
			throw InvalidSyntax();
		}
	}
	
	while (!_data.empty())
	{
		std::cout << _data.top() << " ";
		_data.pop();
	}
	std::cout << std::endl;
}
