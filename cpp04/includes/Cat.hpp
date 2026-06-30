#pragma once

#include "Animal.hpp"

class Cat
{
	protected:

		std::string	type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		Cat();
		Cat(std::string &type);
		Cat(Cat const &src);
		Cat& operator=(Cat const &src);
		virtual	~Cat();

		/*METODOS PROPIOS*/
		std::string			getType() const;
		virtual void		makeSound() const;

};
