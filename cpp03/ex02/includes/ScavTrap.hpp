#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:


	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap&	operator=(const ScavTrap &other);
		~ScavTrap();

		//funcion propia solo del hijo
		void	guardGate();

		// estas funciones estan en la clase madre,
		// pero como sus mensajes mencionan a la madre
		// necesitamos que muestren los mensajes
		// propios de su clase, asi que las mencionamos en el hpp
		// y las volvemos a desarrollar con los mensajes propios de su
		// clase (el hijo)
		void	attack(const std::string& target);
};

#endif