#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iomanip>


# define NAN_DOUBLE "nan"
# define NAN_FLOAT "nanf"
# define INF_POS_DOUBLE "+inf"
# define INF_NEG_DOUBLE "-inf"
# define INF_POS_FLOAT "+inff"
# define INF_NEG_FLOAT "-inff"

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


Los tres ejercicios, en una frase cada uno

	ex00 (ScalarConverter):		conversión de tipos escalares (char/int/float/double)
								a partir de un string — pensado para static_cast.

	ex01 (Serializer):			convertir un puntero a un entero sin signo y viceversa,
								sin tocar ni interpretar los datos — pensado para
								reinterpret_cast.

	ex02 (Identify real type):	dado un Base* o Base&, averiguar el tipo dinámico
								real (A, B o C) sin usar
								typeid — pensado para dynamic_cast.

*/

class ScalarConverter
{
	private:	/*si todo lo pongo bajo la categoria de private no es necesario
				hacer la clase abstracta para hacerla ininstanciable*/

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);

		/*funcion auxiliar para imprimir:*/
		static void	displayAll(const double &av);

	/*convert si lo necesitamos en public ya que esta si lo llamamos desde el main*/

	public:

		static void convert(const std::string &av);
};

#endif

