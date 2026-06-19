#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;		//se pasa por puntero (*)
									//porque en este caso
									//puede ser NULL

	public:
		HumanB(std::string name);	//no se pasa weapon porque este
									//solo nace con nombre
		~HumanB();
		void	attack();
		void	setWeapon(Weapon& weapon);

};

#endif
