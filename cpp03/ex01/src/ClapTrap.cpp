#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout	<< "Constructor Default called"
				<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10),
_energyPoints(10) , _attackDamage(0)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout	<< "Claptrap " << _name << " can't attack"
					<< std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout	<< "Claptrap " << _name << " attacked at " << target
				<< " causing " << _attackDamage
				<< std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "ClapTrap "<< _name << " is alredy dead..."
					<< std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout	<< "Claptrap " << _name << " took " << amount
				<< " points of damage! " << _hitPoints
				<< " HP remaining."
				<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "ClapTrap "<< _name << " is alredy dead..."
					<< " can't be repaired..."
					<< std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout	<< "ClapTrap "<< _name << " has no energy..."
					<< "can't be repaired..."
					<< std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout	<< "Claptrap " << _name << " repaired " << amount
				<< " points of health! "
				<< std::endl << _hitPoints
				<< " HP remaining."
				<< std::endl << _energyPoints
				<< " energy points remaining."
				<< std::endl;
}