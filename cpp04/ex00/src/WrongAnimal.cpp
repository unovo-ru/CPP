#include "WrongAnimal.hpp"

using std::cout; using std::endl;

WrongAnimal::WrongAnimal() : _type("")
{
	cout	<< "WrongAnimal Default contructor called"
			<< endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	cout	<< "WrongAnimal constructor called"
			<< endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : _type(src._type)
{
	cout	<< "WrongAnimal copy constructor called"
			<< endl;
}

WrongAnimal::~WrongAnimal()
{
	cout	<< "WrongAnimal destructor called"
			<< endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	cout	<< "Some generic wrong animal sound"
			<< endl;
}