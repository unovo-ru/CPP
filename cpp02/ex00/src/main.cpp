#include "Fixed.hpp"

int	main()
{
	Fixed	a;		//1. Dispara Constructor por defecto
	Fixed	b(a);	//2. Dispara Constructor de copia
	Fixed	c;		//3. Dispara Constructor por defecto

	c = b;			//4. Dispara Operador de asignación

	std::cout	<< a.getRawBits()
				<< std::endl;
	std::cout	<< b.getRawBits()
				<< std::endl;
	std::cout	<< c.getRawBits()
				<< std::endl;
	return (0);
}
