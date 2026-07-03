#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat :
			public WrongAnimal
{
	protected:

		// std::string	type;
	
	
	public:
	
		/*FORMA CANONICA ORTODOXA*/
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat& operator=(WrongCat const &src);
		~WrongCat();

		/*METODOS PROPIOS*/
		void		makeSound() const;

};

#endif