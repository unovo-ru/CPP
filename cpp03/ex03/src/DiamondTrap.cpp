#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unnamed_clap_name"),
	ScavTrap("unnamed_clap_name"), FragTrap("unnamed_clap_name")
{
	
	_name = "unnamed";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = 50;
	_attackDamage = FragTrap::_attackDamage;
	std::cout	<< "(DIAMOND) Constructor Default called"
				<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_attackDamage = FragTrap::_attackDamage;
	_energyPoints = 50;
	std::cout	<< "(DIAMOND) Constructor called"
				<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "(DIAMOND) Destructor called"
				<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other),
ScavTrap(other), FragTrap(other)
{
	std::cout	<< "(DIAMOND) Copy constructor called"
				<< std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout	<< "DiamondTrap " << _name
				<< std::endl
				<< "ClapTrap " << FragTrap::_name
				<< std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
