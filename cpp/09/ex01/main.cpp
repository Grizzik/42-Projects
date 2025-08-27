#include "RPN.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << BAD_INPUT << std::endl;
		return (1);
	}

	RPN solver;
	try
	{
		solver.solveRPN(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}