#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout	<< "Ice Default constructor called"
				<< std::endl;
}

Ice::~Ice()
{
	std::cout	<< "Ice Destructor called"
				<< std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout	<< "Ice constructor called"
				<< std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria*	Ice::clone() const
{
	/*
	1.-	Devuelve AMateria*: Cumple con la firma exacta de la interfaz.
	
	2.-	No rompe la clase abstracta: No intentamos instanciar AMateria directamente;
		instanciamos un Ice real
	
	3.-	Es una copia profunda potencial: Al pasarle *this,
		se invoca a tu constructor de copia (Ice::Ice(const Ice &src)),
		asegurando que si la clase tuviera atributos complejos, se copiarían
		correctamente en el heap.*/
	return (new Ice(*this));
	/*no podriamos devolver un AMateria directamente debido a que es imposible
	de instanciar, por eso devolviendo su puntero en el prototipo de la funcion
	y creando una clase derivada de la misma cumplimos con el requisito*/
}

void	Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName() << " *"
				<< std::endl;
}

