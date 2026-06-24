#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y){}

Point::~Point()
{
	// std::cout	<< "Destructor called"
				// << std::endl;
}

Point& Point::operator=(Point const &rhs)
{
	/*Como _x e _y son constantes, no podemos
	reasignarlas. La forma canónica exige que el operador exista,
	así que cumplimos con el trámite:*/
	(void)rhs;
	return (*this);
	/*al ser constantes no se pueden modificarlos
	pero la forma canonica ortodoxa exige un operador
	de asignacion obligatoriamente, asi que
	hacemos el casteo a void:
	
	1.-	La escuela te obliga a poner el operator=.

	2.-	El compilador te prohíbe que ese operator=
	intente modificar los valores porque son const.*/
}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}