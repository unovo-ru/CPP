#include "ScavTrap.hpp"

int	main()
{
	{
		ScavTrap	scav("Ulises");

		scav.attack("Juansito");
		scav.guardGate();
		scav.takeDamage(5);
		scav.beRepaired(5);
	}

	{
		ClapTrap	clap("Juansito");
		clap.attack("Ulises");
		clap.takeDamage(5);
		clap.beRepaired(5);
	}
	return (0);
}