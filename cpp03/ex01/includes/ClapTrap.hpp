#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
class ClapTrap
{
	private:

		std::string	_name;			// nombre
		int			_hitPoints;		// puntos de salud (10)
		int			_energyPoints;	// puntos de energia (10)
		int			_attackDamage;	// puntos de ataque (0)


	public:

		//CONSTRUCTORES
		ClapTrap();
		ClapTrap(std::string name);

		//DESTRUCTOR
		~ClapTrap();

		//CONSTRUCTOR DE COPIA
		ClapTrap(const ClapTrap &other);

		//OPERADOR DE ASIGNACION
		ClapTrap&	operator=(const ClapTrap &other);

		//METODOS PUBLICOS
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif