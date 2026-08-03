#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

/*tipos de casteo:

En C, para convertir tipos usabas el cast estilo C: (int)x, (float*)ptr, etc.
Es un cast "todopoderoso" pero peligroso: hace de todo (conversión numérica,
quitar const, reinterpretar bits, downcast entre punteros...)
sin decirte qué está pasando realmente ni avisarte si te equivocas.

C++ separa esa responsabilidad en 4 herramientas explícitas, cada una con una
intención clara:

	static_cast			→ conversiones "razonables" en tiempo de compilación
						(int↔float, upcast en jerarquías, etc.)
	
	dynamic_cast		→ conversión segura en tiempo de ejecución entre tipos
						polimórficos (necesita RTTI, o sea virtual)

	const_cast			→ añadir/quitar const (y nada más)

	reinterpret_cast	→ reinterpretar bits crudos, sin ninguna garantía de
						seguridad (ej. puntero ↔ entero)
*/

class ScalarConverter
{

};

#endif