#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Ulises");
	ClapTrap b(a);
	ClapTrap c(b);

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(3);

	// Test sin energia
	ClapTrap d("NoEnergy");
	for (int i = 0; i < 10; i++)
		d.attack("Enemy");
	d.attack("Enemy"); // sin energia

	// Test sin vida
	ClapTrap e("NearDead");
	e.takeDamage(10);
	e.attack("Enemy"); // sin vida
	e.beRepaired(5);   // sin vida

	return (0);
}