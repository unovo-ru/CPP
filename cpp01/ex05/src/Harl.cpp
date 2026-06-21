#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout	<< "[ DEBUG ]" << std::endl
				<< "I love having extra bacon for my 7-cheese-double-pickle-triple-burger. I really do!"
				<< std::endl;
}
void	Harl::info(void)
{
	std::cout	<< "[ INFO ]" << std::endl
				<< "I cannot believe adding extra bacon costs more money."
				<< std::endl;
}
void	Harl::warning(void)
{
	std::cout	<< "[ WARNING ]" << std::endl
				<< "I think I deserve to have some extra bacon for free. I’ve been coming for years"
				<< std::endl;
}
void	Harl::error(void)
{
	std::cout	<< "[ ERROR ]" << std::endl
				<<  "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}
void	Harl::complain(std::string level)
{
	std::string	instructions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	/*como he usado el typedef no necesito decir que tipo de dato es como si
	he hecho en el [std::string instructions]

	asi quedaria en caso de no poner el typedef:

	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning
	&Harl::error};
	1.-	functions[4]: Es un array de 4 elementos.
	2.-	(Harl::*): Cada uno de esos elementos es un puntero a la clase Harl.
	3.-	void ... (void): Apuntan a funciones que no reciben nada y devuelven void.*/
	
	harlFuntions functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,};
	for (int i = 0; i < 4; i++)
	{
		if (level == instructions[i])
		{
			/*el [this->*] es un "puente hacia la funcion" */
			(this->*functions[i])();//esta forma de escribir la sintaxis es obligatoria
									//para indicar que vamos a pasar la funcion apuntada
									//por el puntero ya que el compilador necesita
									//resolver primero la direccion (funcion) antes de devolverla
			return ;
		}
	}
	std::cout	<< "wrong instructions for Harl"
				<< std::endl;
}