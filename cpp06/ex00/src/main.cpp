#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	// std::cout	<< "este es av 1: " << av[1] << std::endl;
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		return (1);
	return (0);
}
