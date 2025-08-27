#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	try {
		if (ac < 2)
			throw FileException("Error: No arguments found!");

		PMM pmm;
		for (int i = 1; i < ac; i++)
		{
			long num = std::atol(av[i]);
			if (num < 0 || num > UINT_MAX)
				throw FileException("Error: Argument is out of range!");
			pmm.push(static_cast<unsigned int>(num));
		}

		pmm.showSequence("Before:\t");
		pmm.sort();
		std::cout << "\n\n" << std::endl;
		pmm.showSequence("After:\t");
		std::cout << std::fixed << std::setprecision(6);
		std::cout << "Time to process a range of " << pmm.getVecSize() << " elements with std::vector :\t"
				  << static_cast<double>(pmm.getVecTime() * 1000000) / CLOCKS_PER_SEC << " us" << std::endl;
		std::cout << "Time to process a range of " << pmm.getLstSize() << " elements with std::list   :\t"
				  << static_cast<double>(pmm.getLstTime() * 1000000) / CLOCKS_PER_SEC << " us" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
