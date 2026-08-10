#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

void	ScalarConverter::displayAll(const double &av)
{
	/*CHAR*/
	{
		double result = round(av);
		if (std::isnan(av) || std::isinf(av))
			std::cout	<< "char: impossible"
						<< std::endl;
		else if (result < 0 || result > 127)
			std::cout	<< "char: impossible"
						<< std::endl;
		else
		{
			char	charResult = static_cast<char>(av);
			if (std::isprint(static_cast<unsigned char>(charResult)))
				std::cout	<< "char: '" << charResult << "'"
							<< std::endl;
			else
				std::cout	<< "char: non displayable"
							<< std::endl;
		}
	}

	/*INT*/
	{
		if (std::isnan(av) || std::isinf(av))
			std::cout	<< "int: impossible"
						<< std::endl;
		else if (av < INT_MIN || av > INT_MAX)
			std::cout	<< "int: impossible"
						<< std::endl;
		else
			std::cout	<< "int: " << static_cast<int>(av)
						<< std::endl;
	}

	/*FLOAT*/
	{
		if (std::isnan(av))
			std::cout	<< "float: nan"
						<< std::endl;
		else if (std::isinf(av))
			std::cout	<< "float: " << (av > 0 ? "inff" : "-inff")
						<< std::endl;
		else
		{
			float floatValue = static_cast<float>(av);
			std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << floatValue;
			if (floatValue == static_cast<long>(floatValue))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
	}

	/*DOUBLE*/
	{
		if (std::isnan(av))
			std::cout	<< "double: nan"
						<< std::endl;
		else if (std::isinf(av))
			std::cout	<< "double: " << (av > 0 ? "inf" : "-inf")
						<< std::endl;
		else
		{
			double doubleValue = static_cast<double>(av);
			std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << doubleValue;
			if (doubleValue == static_cast<long>(doubleValue))
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
}

void ScalarConverter::convert(const std::string &av)
{
	/*0.-para string vacio*/
	if (av.empty())
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: impossible" << std::endl
					<< "double: impossible" << std::endl;
		return ;
	}

	/*1.-para el char literal*/
	if (av.size() == 1 && (std::isprint(static_cast<unsigned char>(av[0]))))
	{
		double charValue = static_cast<double>(av[0]);
		std::cout	<< charValue << std::endl;
		displayAll(charValue);
		return;
	}
	/*2.-para pseudoliteral*/
	if (av == NAN_DOUBLE)
	{
		double value = std::numeric_limits<double>::quiet_NaN();
		displayAll(value);
		return ;
	}
	else if (av == NAN_FLOAT)
	{
		double value = std::numeric_limits<float>::quiet_NaN();
		displayAll(value);
		return ;
	}
	else if (av == INF_POS_DOUBLE)
	{
		double value = std::numeric_limits<double>::infinity();
		displayAll(value);
		return ;
	}
	else if (av == INF_NEG_DOUBLE)
	{
		double value = -std::numeric_limits<double>::infinity();
		displayAll(value);
		return ;
	}
	else if (av == INF_POS_FLOAT)
	{
		double value = std::numeric_limits<float>::infinity();
		displayAll(value);
		return ;
	}
	else if (av == INF_NEG_FLOAT)
	{
		double value = -std::numeric_limits<float>::infinity();
		displayAll(value);
		return ;
	}

	/*3.-para float*/
	if (av[av.length() - 1] == 'f')
	{
		std::string num = av.substr(0, av.length() - 1);
		char *endptr = NULL;
		float floatValue = strtof(num.c_str(), &endptr);
		if (*endptr == '\0' && !num.empty())
			displayAll(floatValue);
		else
			std::cout	<< "char: impossible" << std::endl
						<< "int: impossible" << std::endl
						<< "float: impossible" << std::endl
						<< "double: impossible" << std::endl;
		return ;
	}

	/*para el double*/
	else if (av.find('.') != std::string::npos)
	{
		char	*endptr = NULL;
		double	doubleValue = strtod(av.c_str(), &endptr);
		if (*endptr == '\0')
			displayAll(doubleValue);
		else
			std::cout	<< "char: impossible" << std::endl
						<< "int: impossible" << std::endl
						<< "float: impossible" << std::endl
						<< "double: impossible" << std::endl;
		return ;
	}

	/*para el int*/
	else
	{
		char	*endptr;
		long	intValue = strtol(av.c_str(), &endptr, 10);
		if (*endptr == '\0' && !av.empty() && intValue >= INT_MIN && intValue <= INT_MAX)
		{
			displayAll(intValue);
		}
		else
		{

			std::cout	<< "char: impossible" << std::endl
						<< "int: impossible" << std::endl
						<< "float: impossible" << std::endl
						<< "double: impossible" << std::endl;
		}
		return ;
	}
}


/*COSAS A TENER EN CUENTA:

nan				→ "Not a Number", representa un resultado sin sentido matemático
				(ej. 0.0/0.0). Versión double.

nanf			→ lo mismo pero como literal de tipo float (la f al final
				indica "float", igual que en 4.2f).

inf / +inf		→ infinito positivo (double). El + es opcional/redundante,
				es solo notación.

-inf 			→ infinito negativo (double).

inff / +inff	→ infinito positivo, versión float.

-inff			→ infinito negativo, versión float.*/









/*FUNCIONES UTILES:

strtod	→	devuelve double. Sirve también para detectar "nan"/"inf"
			automáticamente si quisieras (aunque tú ya los gestionas aparte
			por comparación exacta).

strtof	→	igual pero devuelve float directamente (útil si quieres parsear
			ya como float sin pasar por double y perder precisión de forma distinta).

strtol	→	para enteros. Firma: long strtol(const char *str, char **endptr, int base)
			— el tercer parámetro es la base numérica (usarías 10 para decimal).
			Devuelve long, no int, así que tendrás que comprobar tú mismo si el
			valor cabe en rango de int.
*/






/*ejemplos validos e invalidos de como debe funcionar el programa:

./convert 'a' / a
char: 'a'
int: 97
float: 97.0f
double: 97.0


./convert '\n'

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0


./convert -42
char: impossible
int: -42
float: -42.0f
double: -42.0


./convert 1234567890123.0
char: impossible
int: impossible
float: impossible
double: 1234567890123.0


./convert +inf
char: impossible
int: impossible
float: inff
double: inf


./convert -4.2f
char: impossible
int: -4
float: -4.2f
double: -4.2


./convert hello
*/