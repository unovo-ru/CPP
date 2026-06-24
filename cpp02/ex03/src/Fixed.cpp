#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/*CONSTRUCTOR DEFAULT*/
Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout	<< "Default constructor called"
	// 			<< std::endl;
}

/*DESTRUCTOR*/
Fixed::~Fixed()
{
	// std::cout	<< "Destructor called"
	// 			<< std::endl;
}

/*SETTER*/
void	Fixed::setRawBits(const int raw)
{
	_fixedPointValue = raw;
}

/*GETTER*/
int	Fixed::getRawBits(void) const
{
	// std::cout	<< "getRawBits member function called"
	// 			<< std::endl;
	return (_fixedPointValue);
}

/*CONSTRUCTOR DE COPIA*/
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	// std::cout	<< "Copy constructor called"
	// 			<< std::endl;
}

/*CONSTRUCTOR DE INT*/
Fixed::Fixed(int const raw) : _fixedPointValue(raw << _fractionalBits)
{
	// std::cout	<< "Int constructor called"
				// << std::endl;
}

/*CONSTRUCTOR DE FLOAT*/
Fixed::Fixed(float const dec) : _fixedPointValue(roundf(dec * 256.0f))
{
	// std::cout	<< "Float constructor called"
				// << std::endl;
}


/*OPERADOR DE ASIGNACION*/
Fixed & Fixed ::operator=(const Fixed &other)
{
	// std::cout	<< "Copy assignment operator called"
				// << std::endl;
	
	if (this == &other)
		return (*this);
	
	this->_fixedPointValue = other.getRawBits();
	return (*this);
}


int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);

	
	/* recuerda que en el pc el número viene escalado en base 2.
	Por ejemplo, el número real 5.42 no se guarda como 542, sino como 
	(5.42 * 256) = 1388.
	Al aplicar el movimiento de bits (>> 8), dividimos de forma entera entre 256,
	desechando los 8 bits fraccionarios y quedándonos solo con la parte entera pura:
	1388 (que representa 5.42) ---> 5 */
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / 256.0f);

/*	Para transformar el valor bruto de punto fijo a un float real,
	hacemos la operación matemática inversa a la del constructor:
	dividir entre 2^8 (256).

	Hacemos un casteo a (float) sobre la variable antes de dividir para forzar 
	a C++ a realizar una división decimal exacta, evitando que
	trunque los decimales.

	Ejemplo: 1388 (punto fijo) -> 1388.0f / 256.0f ===> 5.421875f
*/
}

/*FUNCION DE RESOLUCION DEL OPERADOR*/
std::ostream &operator<<(std::ostream &outputScreen, Fixed const &obj)
{
	outputScreen << obj.toFloat();
	return (outputScreen);
}



/*NUEVOS OPERADORES*/
/*OPERADOR DE ASIGNACION*/



bool Fixed::operator>(const Fixed &other) const
{
	return (_fixedPointValue > other._fixedPointValue);
}

/*		es lo mismo que:

bool Fixed::operator>(const Fixed &other) const
{
	if (_fixedPointValue > other._fixedPointValue)
		return (true);
	return (flase);

}*/



bool	Fixed::operator<(const Fixed &other) const
{
	return (_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_fixedPointValue != other._fixedPointValue);
}



/*OPERADORES DE OPERACIONES MATEMATICAS:*/

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return (result);

}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0)
		return (std::cerr << "Error, no valid calc" << std::endl, Fixed(0));
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed& Fixed::operator++(int)
{
	Fixed	*i = this;
	this->_fixedPointValue++;
	return (*i);
}

Fixed& Fixed::operator--(int)
{
	Fixed	*i = this;
	this->_fixedPointValue--;
	return (*i);
}

//USO DE TERNARIOS PARA COMPROBACION Y RETURN
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a > b ? b : a);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}


