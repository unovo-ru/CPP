#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;		//se pasa por referencia (&)
									//porque no es una copia
									//sino la que hemos creado
									//con su constructor.

	public:
		HumanA(std::string name, Weapon& weapon);	//se pasa por referencia (&)
													//porque no es una copia
													//sino la que hemos creado
													//con su constructor.
		~HumanA();
		void	attack();

};

#endif
