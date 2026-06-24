#include "Point.hpp"

/*hacemos una funcion auxiliar para calcular el signo de
un punto respecto a una linea (positivo a un lado de la linea,
negativo al otro lado de la linea)*/

Fixed	sign(Point	p, Point const l1, Point const l2)
{
	/*p es el punto, l1 es el primer punto que conforma
	la linea y l2 es el segundo, representamos el punto
	y la linea*/

	return ((p.getX() - l2.getX()) * (l1.getY() - l2.getY()) -
		(l1.getX() - l2.getX()) * (p.getY() - l2.getY()));

	/*esta formula es el determinante de dos vectores:
	Si el punto p está a tu izquierda, la fórmula escupirá
	un número positivo (>0).

	Si el punto p está a tu derecha, la fórmula escupirá un
	número negativo (<0).

	Si el punto p está justo en medio de la carretera (en la línea),
	la fórmula dará exactamente cero (=0).*/
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	/*declaramos 3 objetos numericos, y en cada uno de ellos vamos a
	meter la relacion entre el punto y cada una de las lineas que conforman
	el triangulo*/

	Fixed	d1, d2, d3;

	// Calculamos la posición relativa del punto respecto a los tres lados
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	if (d1 > 0 && d2 > 0 && d3 > 0)
		return (true);
	else if (d1 < 0 && d2 < 0 && d3 < 0)
		return (true);
	else
		return (false);

	/*tambien se puede hacer de la siguiente forma:
	
	
	bool	todosPositivos = (d1 > 0 && d2 > 0 && d3 > 0);
	bool	todosNegativos = (d1 < 0 && d2 < 0 && d3 < 0);
	
	return (todosPositivos || todosNegativos);
	
	*/
}
