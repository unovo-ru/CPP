#include "FragTrap.hpp"

int main()
{
	{
		FragTrap	frag("Ulises");

		frag.attack("Juansito");
		frag.highFivesGuys();
		frag.takeDamage(5);
		frag.beRepaired(5);
	}

	{

		ScavTrap	scav("Juansito");

		scav.guardGate();
		scav.attack("Ulises");
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