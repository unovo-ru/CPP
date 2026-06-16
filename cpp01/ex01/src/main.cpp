#include "Zombie.hpp"

int	main(void)
{

	Zombie* juansitosHorde = zombieHorde(5, "Juansito");


	std::cout	<< std::endl
				<< "---------JUANSITO IS ALIIIIIVEEEEE!! (in the stack)---------"
				<< std::endl;
	for (int i = 0; i < 5; i++)
		juansitosHorde[i].announce();
	std::cout	<< std::endl
				<< "---------FINISH THEM---------!!"
				<< std::endl;
	delete[] juansitosHorde;
	return (0);
}