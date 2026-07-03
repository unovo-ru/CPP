#include "Cat.hpp"

using std::cout; using std::endl;

Cat::Cat() : Animal("Cat")
{
	cout	<< "Default cat constructor called"
			<< endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	cout	<< "Copy cat constructor called"
			<< endl;
}

Cat& Cat::operator=(Cat const &src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Cat::~Cat()
{
	cout	<< "Cat destructor called"
			<< endl;
}

void	Cat::makeSound() const
{
	cout	<< "Miau... ñaa ñaa ñaa"
			<< endl;
}
