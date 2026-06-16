#include "Zombie.hpp"

int	main(void)
{
	//primero imprimimos con la funcion que crea en stack
	std::cout	<< std::endl
				<< "---------HE IS ALIIIIIVEEEEE!! (in the stack)---------"
				<< std::endl;
	randomChump("Bobby");
	//no necesitamos de annouunce
	std::cout	<< std::endl
				<< "---------OH, WAIT... NAH HE DIED---------"
				<< std::endl;

	//despues hacemos lo propio con la del heap
	std::cout	<< std::endl
				<< "---------HE IS ALIIIIIVEEEEE!! (in the heap)---------"
				<< std::endl;
	Zombie* myZombie = newZombie("Ronny");
	
	/*a diferencia de en randomChump aqui para que se anuncie tenemos que llamar 
	manualmente a annonuce porque sigue Ronny sigue vivo desde que se creó
	
	en esta ocasion no hacemos myZombie.announce() como hasta ahora
	porque no podemos olvidar que esta vez se trata de un puntero
	igual que en C*/
	
	myZombie->announce();
	std::cout	<< std::endl
				<< "---------FINISH HIM---------!!"
				<< std::endl;
	//ahora hacemos el delete para el new de newZombie

	delete myZombie;
	return (0);
}