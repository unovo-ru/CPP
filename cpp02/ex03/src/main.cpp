#include "Point.hpp"

int main(void)
{
	// Creamos un triángulo equilátero/isósceles simple
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(5.0f, 10.0f);

	// Caso 1: Un punto claramente en el centro del triángulo
	Point const into(5.0f, 3.0f);
	
	// Caso 2: Un punto completamente in
	Point const	out(12.0f, 5.0f);
	
	// Caso 3: Un punto posado JUSTO en la línea de la base (y = 0)
	Point const	inLine(5.0f, 0.0f);

	std::cout	<< "Punto into (esperado: 1): "
				<< bsp(a, b, c, into) << std::endl;
	std::cout	<< "Punto out (esperado: 0): "
				<< bsp(a, b, c, out) << std::endl;
	std::cout	<< "Punto en arista (esperado: 0): "
				<< bsp(a, b, c, inLine) << std::endl;

	return (0);
}
