#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:

		std::string	_type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		virtual	~Animal();

		/*METODOS PROPIOS*/
		std::string			getType() const;
		virtual void		makeSound() const;

};

/*DIFERENCIAS ENTRE PONER EL CONST AL INICIO O AL FINAL:

const std::string getType();			esto dice "el string que devuelvo es const"
										no afecta al objeto
std::string getType() const;			esto dice "este método no modifica *this"

*/
#endif