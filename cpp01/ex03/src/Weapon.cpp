#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon()
{
	std::cout	<< _type << " Eliminated."
				<< std::endl;
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

const std::string&	Weapon::getType()
{
	return (_type);
}