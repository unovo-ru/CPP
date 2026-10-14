#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw PmergeMe::Error("Error: No sequence provided.");
		PmergeMe toOrder(ac, av);
		toOrder.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}