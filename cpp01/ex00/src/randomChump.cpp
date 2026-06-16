#include "Zombie.hpp"

/*en este no devolvemos un puntero,
no queremos que el zombie que nace viva tras 
el periodo de vida de la funcion que lo crea*/

/*esta funcion si necesita de announceya que 
una vez muera la funcion muere el zombie
asi que no tiene oportunidad en ningun
otro sitio para anunciarse*/

void	randomChump(std::string name)
{
	Zombie	myZombie(name);
	myZombie.announce();
}