#include "Dog.hpp"

using std::cout; using std::endl;

Dog::Dog() : Animal("Dog")	//puedo llamar en el DC hijo a un constructor no default padre
{
	cout	<< "Default Dog constructor called"
			<< endl;
}
Dog::Dog(Dog const &src) : Animal(src)	//puedo usar el constructor de copia padre
{
	// Animal::operator=(src);			es lo mismo que llamarlo dentro del cuerpo
	//									de la propia funcion
	cout	<< "Copy constructor Dog called"
			<< endl;
}
Dog& Dog::operator=(Dog const &src)
{
	if (this != &src)
		Animal::operator=(src);
	// cout	<< "Asignation operator Dog called"
	// 		<< endl;
	return (*this);
}
Dog::~Dog()
{
	cout	<< "Destructor Dog called"
			<< endl;	
}
void	Dog::makeSound() const
{
	cout	<< "Wof wof...!!"
			<< endl;
}