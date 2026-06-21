#include "Harl.hpp"

int	getLevel(std::string level)
{
	std::string	instructions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (level == instructions[i])
			return (i);
	return (-1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout	<< "wrong instructions for Harl", 1);
	Harl	instruction;
	int	level = getLevel(av[1]);


	/*APRENDEMOS A USAR AL SWITCH, AQUI DEBO QUITAR LOS BREAKS
	QUE OBLIGATORIAMENTE IRIAN EN CADA UNO DE LOS CASOS PORQUE
	UNA VEZ ENTRE EN UNO, QUIERO QUE ENTRE EN LOS DEMAS

	ASI QUE PARA QUE EL COMPILADOR NO SE ASUSTE DEBO PONER:
	[// fallthrough] PARA QUE SEPA QUE VA EN CAIDA LIBRE*/
	
	switch (level)
	{
		case 0:
			instruction.complain("DEBUG");
			// fallthrough
		case 1:
			instruction.complain("INFO");
			// fallthrough
		case 2:
			instruction.complain("WARNING");
			// fallthrough
		case 3:
		{
			instruction.complain("ERROR");
			// fallthrough
			break;
		}
		default:
		{
			std::cout	<< "wrong instructions for Harl"
						<< std::endl;
			break;
		}
	}
	return (0);
}