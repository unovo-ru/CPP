#include "Zombie.hpp"

/*esta funcion devuelve un puntero porque
queremos crear un zombie que no muera
cuando su funcion acabe, sino que siga viviendo
en el Heap (memoria dinamica)*/

/*esta funcion no necesita de announce porque
como se va a aguardar para despues, se puede anunciar despues*/

Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}
/*es lo mismo que:

	Zombie*	mi_zombie = new Zombie(name);
	return (mi_zombie);

*/