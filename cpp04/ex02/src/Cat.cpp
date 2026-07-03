#include "Cat.hpp"

using std::cout; using std::endl;

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	// _brain = new Brain();
	cout	<< "Default cat constructor called"
			<< endl;
}

Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	cout	<< "Copy cat constructor called"
			<< endl;
}

Cat& Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		delete _brain;
		_brain = new Brain(*src._brain);
		Animal::operator=(src);
	}
	return (*this);
}

Cat::~Cat()
{
	cout	<< "Cat destructor called"
			<< endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	cout	<< "Miau... ñaa ñaa ñaa"
			<< endl;
}

Brain* Cat::getBrain() const
{
	return (this->_brain);
}