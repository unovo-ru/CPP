#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:

		std::string	_type;
	
	
	public:
	
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		virtual	~Animal();

		std::string			getType() const;

		/*para convertirla en un metodo virtual puro
		se iguala a cero de este modoc puedes forzar a nivel
		de compilador un requisito de diseño: "nadie puede crear un
		Animal genérico, solo subtipos concretos".
		El compilador se convierte en tu guardián del diseño.*/
		virtual void		makeSound() const = 0;

};

#endif