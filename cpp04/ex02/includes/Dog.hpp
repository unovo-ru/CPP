#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog :
			public Animal
{

	private:

		Brain	*_brain;

	public:
	
						Dog();

						Dog(Dog const &src);
		Dog&			operator=(Dog const &src);
		virtual			~Dog();

		virtual void	makeSound() const;		//ya es virtual al heredarlo de Animal
		Brain*			getBrain() const;
};

#endif