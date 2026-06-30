#pragma once
#include "Animal.hpp"

class Dog
{
	protected:

		std::string	type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		Dog();
		Dog(std::string &type);
		Dog(Dog const &src);
		Dog& operator=(Dog const &src);
		virtual	~Dog();

		/*METODOS PROPIOS*/
		std::string			getType() const;
		virtual void		makeSound() const;

};
