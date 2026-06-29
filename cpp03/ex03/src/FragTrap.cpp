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

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout	<< "Fragtrap " << _name << " can't attack"
					<< std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout	<< "Fragtrap " << _name << " attacked at " << target
				<< " causing " << _attackDamage
				<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "FragTrap "<< _name << " is alredy dead..."
					<< std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout	<< "FragTrap " << _name << " took " << amount
				<< " points of damage! " << _hitPoints
				<< " HP remaining."
				<< std::endl;
}
void	FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "FragTrap "<< _name << " is alredy dead..."
					<< " can't be repaired..."
					<< std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout	<< "FragTrap "<< _name << " has no energy..."
					<< "can't be repaired..."
					<< std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout	<< "FragTrap " << _name << " repaired " << amount
				<< " points of health! "
				<< std::endl << _hitPoints
				<< " HP remaining."
				<< std::endl << _energyPoints
				<< " energy points remaining."
				<< std::endl;
}