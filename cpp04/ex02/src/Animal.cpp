#include "Animal.hpp"

using std::cout; using std::endl;

Animal::Animal() : _type("")
{
	cout	<< "Animal Default contructor called"
			<< endl;
}

Animal::~Animal()
{
	cout	<< "Animal destructor called"
			<< endl;
}

Animal::Animal(std::string const &type) : _type(type)
{
	cout	<< "Animal constructor called"
			<< endl;
}

Animal::Animal(Animal const &src) : _type(src._type)
{
	cout	<< "Animal copy constructor called"
			<< endl;
}

Animal& Animal::operator=(Animal const &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (_type);
}

// void	Animal::makeSound() const
// {
// 	cout	<< "Some generic animal sound"
// 			<< endl;
// }
