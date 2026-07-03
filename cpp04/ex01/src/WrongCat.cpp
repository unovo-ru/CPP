#include "WrongCat.hpp"

using std::cout; using std::endl;

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout	<< "Default WrongCat constructor called"
			<< endl;
}
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	cout	<< "Copy WrongCat constructor called"
			<< endl;
}
WrongCat& WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}
WrongCat::~WrongCat()
{
	cout	<< "WrongCat destructor called"
			<< endl;
}
void	WrongCat::makeSound() const
{
	cout	<< "Not Miau Miau... actually"
			<< endl;
}