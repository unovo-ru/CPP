#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	_name = ClapTrap::_name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout	<< "(DIAMOND) Constructor Default called"
				<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
ScavTrap(name), FragTrap(name)
{
	// _name = ClapTrap::_name;
	// _hitPoints = FragTrap::_hitPoints;
	// _energyPoints = ScavTrap::_energyPoints;
	// _attackDamage = FragTrap::_attackDamage;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
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
				<< "ClapTrap " << ClapTrap::_name
				<< std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout	<< "DiamondTrap " << _name << " can't attack"
					<< std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout	<< "DiamondTrap " << _name << " attacked at " << target
				<< " causing " << _attackDamage
				<< std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "DiamondTrap "<< _name << " is alredy dead..."
					<< std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout	<< "DiamondTrap " << _name << " took " << amount
				<< " points of damage! " << _hitPoints
				<< " HP remaining."
				<< std::endl;
}
void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "DiamondTrap "<< _name << " is alredy dead..."
					<< " can't be repaired..."
					<< std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout	<< "DiamondTrap "<< _name << " has no energy..."
					<< "can't be repaired..."
					<< std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout	<< "DiamondTrap " << _name << " repaired " << amount
				<< " points of health! "
				<< std::endl << _hitPoints
				<< " HP remaining."
				<< std::endl << _energyPoints
				<< " energy points remaining."
				<< std::endl;
}