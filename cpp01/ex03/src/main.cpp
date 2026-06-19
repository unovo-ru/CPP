#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int	main()
// {
	// Weapon	club = Weapon("crude spiked club");
	// HumanA	bob = HumanA("Bob", club);
	// HumanB	rob = HumanB("Rob");
// 
	// bob.attack();
	// rob.attack();
	// rob.setWeapon(club);
	// rob.attack();
	// return (0);
// }

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	/*EL PROGRAMA SE DIVIDE EN 2 BLOQUES, AL CERRARSE UN PROCESO
	EN UNAS LLAVES EL DESTRUCTOR ACTUA ANTES DE PASAR AL SIGUIENTE BLOQUE*/
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}

	std::cout << "---------------------------------------" << std::endl;

	{
		Weapon club = Weapon("crude spiked club");

		HumanB rob("Rob");
		rob.setWeapon(club);
		rob.attack();

		club.setType("some other type of club");
		rob.attack();
	}

	return (0);
}