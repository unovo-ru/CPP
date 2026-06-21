#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout	<< "wrong instructions for Harl", 1);
	Harl	instruction;
	instruction.complain(av[1]);
	return (0);
}