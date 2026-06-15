#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout	<< _name << " ha sido completamente aniquilado."
				<< std::endl;
}

