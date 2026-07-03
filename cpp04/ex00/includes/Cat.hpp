#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat :
			public Animal
{
	protected:

		// std::string	type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		Cat();
		Cat(Cat const &src);
		Cat& operator=(Cat const &src);
		virtual	~Cat();

		/*METODOS PROPIOS*/
		virtual void		makeSound() const;

};

#endif