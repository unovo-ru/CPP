#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "(FRAG) Constructor Default called"
				<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "(FRAG) Constructor called"
				<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout	<< "(FRAG) Destructor called"
				<< std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout	<< "(FRAG) Copy constructor called"
				<< std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout	<< "FragTrap " << _name
				<< " is requesting a high five!"
				<< std::endl;
}
