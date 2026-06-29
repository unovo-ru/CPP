#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class	FragTrap: public ClapTrap
{
	private:


	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap&	operator=(const FragTrap &other);
		~FragTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	highFivesGuys(void);

};

#endif