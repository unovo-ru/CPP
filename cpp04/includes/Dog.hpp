#pragma once
#include "Animal.hpp"

class Dog :
			public Animal
{
	protected:

		/*ya hereda std::string	_type de Animal,
		no es necesariorepetirlo*/

	public:
	
		/*FORMA CANONICA ORTODOXA*/
		Dog();
		
		//Dog(std::string const &type);
		/*no lo necesitamos porque el subject dice que Dog siempre es Dog*/

		Dog(Dog const &src);
		Dog& operator=(Dog const &src);
		virtual	~Dog();

		/*METODOS PROPIOS*/
		std::string			getType() const;
		virtual void		makeSound() const;		//ya es virtual al heredarlo de Animal
													//solo se vuelve a poner por legibilidad

		/*el virtual sirve para cuando cree un Dog a partir de un
		
		Animal: --> Animal	*i = new Dog()
		
		en el momento de llamar a la funcion con virtual (makeSound)
		el compilador elija que makeSound quiero hacer, en funcion del objeto
		con el que trabajo, no desde el que heredo:
		
		i->makeSound();		--> ¿se ejecuta Animal::makeSound() o Dog::makeSound()?

		SE EJECUTA DOG::MAKESOUND
		*/
};
