#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"


class DiamondTrap :
			virtual public ScavTrap,
			virtual public FragTrap					//cuando hay mas de un padre
{													//se ponen los que sean separados
	private:										//por comas.
		std::string	_name;

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap&	operator=(const DiamondTrap &other);
		~DiamondTrap();


		void	whoAmI();
		void	attack(const std::string& target);
};

#endif