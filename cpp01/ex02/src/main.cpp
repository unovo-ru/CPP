#include <iostream>
#include <string>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";

	/*un puntero es una variable que guarda una direcion de memoria:
	
	[* almacena un --> &]
	[VARIABLE almacena un --> 0x7ffe9f4e3038]*/

	/*el puntero apunta a la direccion de memoria (&) de la variable (str),
	donde he almacenado el "HI THIS IS BRAIN"*/

	std::string *stringPTR = &str; // -> su puntero apunta a 0x7ffe9f4e3038
	
	/*str es literlamente "HI THIS IS BRAIN", y en este caso lo
	lo estoy almacenando dentro de la direccion de memoria (referencia)
	de stringREF*/

	std::string &stringREF = str;
	/*Al hacer std::string &stringREF = str;, estás diciendo:
	"A partir de ahora, la variable str también se puede llamar stringREF".

	Son exactamente la misma cosa en la memoria RAM. No se crea una dirección
	nueva para stringREF.*/

	/*siempre que quiera escribir (o trabajar con) una direccoion de
	memoria se va a trabajr con &*/
	std::cout	<< &str << std::endl
				<< stringPTR << std::endl
				/*		|
				en este caso si hiciera:
				&stringPTR << std::endl
				me estaria imprimiento la direccion
				de memoria del propio punero (*)
				
				imprimo la variable directamente porque
				es la variable al que almacena la direccion
				de memoria */
				
				<< &stringREF << std::endl;

	/*
		int	a = 42;	  --->	almaceno contenido
		int	*p = &a;  --->	el puntero guarda la direccion de ese contenido
		int	&r = a;	  --->	la direccion de la variable r, ahora es a
							es decir, todo lo que le pase a a, le pasa a r
							y viceversa:

				a = 3; ---> r = 3 y ademas, *p = 3;
	*/

	std::cout	<< str << std::endl
				<< *stringPTR << std::endl
				<< stringREF << std::endl;

	return (0);
}