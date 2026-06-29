#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap	//cuando hay mas de un padre
{														//se ponen los que sean separados
	private:											//por comas.


	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap&	operator=(const DiamondTrap &other);
		~DiamondTrap();


		void	whoAmI();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif