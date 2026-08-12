#include "Templates.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	/*IGUALES INT*/
	{
		std::cout	<< "para cuando son iguales"
					<<std::endl;
		int	a = 3;
		int	b = 3;
		std::cout	<< ::min(a, b)
					<< std::endl;
		
	}
	/*MAYOR VS MENOR*/
	{
		std::cout	<< "para cuando valen distinto"
					<<std::endl;
		int a = 6;
		int b = 7;
		int c = ::min(a, b);
		std::cout	<< "pasamos min " << c << std::endl;

		c =::max(a, b);
		std::cout	<< "pasamos max " << c << std::endl;
	}

	/*INTERCAMBIO*/
	{
		char	a = 'a';
		char	b = 'b';

		std::cout	<< "esto es antes de intercambiar"
					<< std::endl;
		std::cout	<< "a = " << a
					<< std::endl
					<< "b = " << b
					<< std::endl;

		::swap(a, b);

		std::cout	<< "esto es despues de intercambiar"
					<< std::endl;
		std::cout	<< "a = " << a
					<< std::endl
					<< "b = " << b
					<< std::endl;
	}

}
