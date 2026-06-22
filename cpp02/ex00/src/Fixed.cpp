#include "Fixed.hpp"

/*CONSTRUCTOR DEFAULT*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

/*DESTRUCTOR*/
Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

/*SETTER*/
void	Fixed::setRawBits(const int raw)
{
	_fixedPointValue = raw;
}

/*GETTER*/
int	Fixed::getRawBits(void) const
{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return (_fixedPointValue);
}

/*CONSTRUCTOR DE COPIA*/
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other.getRawBits())
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
	/*he asignado el valor fuera de las llaves,
	pero tambien se podria:

	this->_fixedPointValue = other.getRawBits
	_fixedPointValue = other.getRawBits
	*/
}

/*OPERADOR DE ASIGNACION*/
Fixed & Fixed ::operator=(const Fixed &other)
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;
	
	//comprobamos que no se trate del mismo para evitar problemas
	//de compilacion
	if (this == &other)
		return (*this);
	
	//asignamos el valor de copia tomando los valores obtenidos
	//del mismo metodo.
	this->_fixedPointValue = other.getRawBits();
	return (*this);

	/*A PARTIR DE AHORA CUANDO EL COMPILADOR VEA ESTA IGUALDAD:
	
	FIXED	A;
	FIXED	B;

	A = B;		-->	VA A LLAMAR A ESTA FUNCION DE FORMA "SECRETA"
					PARA REALIZAR ESTE METODO DE COPIA.
	*/
}
