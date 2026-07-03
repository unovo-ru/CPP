#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:

		std::string	_type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		WrongAnimal();
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal& operator=(WrongAnimal const &src);
		~WrongAnimal();

		/*METODOS PROPIOS*/
		std::string			getType() const;
		void		makeSound() const;

};

#endif