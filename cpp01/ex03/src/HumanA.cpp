#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){}

HumanA::~HumanA()
{
	std::cout	<< _name << " Eliminated."
				<< std::endl;
}
void	HumanA::attack()
{
	// std::cout	<< std::endl
				// << "D*mn " << _name
				// << " get the sh*t out of them with their "
				// << _weapon.getType()
				// << std::endl;
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}