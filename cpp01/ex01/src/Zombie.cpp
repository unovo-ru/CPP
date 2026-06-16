#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout	<< _name << " has been completely annihilated."
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout	<< _name << ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}