#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB()
{
	std::cout	<< _name
				<< " Eliminated."
				<< std::endl;
}

void	HumanB::attack()
{
	if (_weapon)
	{
		// std::cout// << "D*mn " << _name
					// << " get the sh*t out of them with their "
					// << _weapon->getType()
					// << std::endl;
		std::cout	<< _name
					<< " attacks with their "
					<< _weapon->getType()
					<< std::endl;
	}
	else
	{
		// std::cout// << _name << " is f****d, has no weapon"
					// << std::endl;
		std::cout	<< _name <<" has no weapon to attack with!"
					<< std::endl;
	}

}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}