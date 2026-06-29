#include "DiamondTrap.hpp"

int	main()
{
	{
		FragTrap	frag("Ulises");

		frag.attack("Juansito");
		frag.highFivesGuys();
		frag.takeDamage(5);
		frag.beRepaired(5);
	}
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	{
		ScavTrap	scav("Juansito");

		scav.guardGate();
		scav.attack("Bonnie");
		scav.takeDamage(5);
		scav.beRepaired(5);

	}
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	{
		ClapTrap	clap("Bonnie");

		clap.attack("Mary");
		clap.takeDamage(5);
		clap.beRepaired(5);
	}
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	{
		DiamondTrap	diamond;

		diamond.attack("Mary");
		diamond.takeDamage(5);
		diamond.beRepaired(5);
		diamond.whoAmI();
		diamond.highFivesGuys();
		diamond.guardGate();
	}
	return (0);
}