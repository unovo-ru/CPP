#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Weapon
{
	private:

		std::string			_type;	//string normal para poder modificarlo

	public:

		Weapon(std::string type);				//constructor que usaremos necesita ponerle
												//un tipo al arma al crearla
		~Weapon();								//destrcutor default
		const std::string&	getType(void);		//getter para acceder al _type privado
		void	setType(std::string newType);	//setter para cambiar el type desde el main
};

#endif
