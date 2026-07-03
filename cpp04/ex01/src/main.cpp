#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	const	WrongAnimal* wrongMeta = new WrongAnimal();
	const	WrongAnimal* WrongI = new WrongCat();
	/*a diferencia del caso anterior tengo que crear wrongcat directamente
	debido a que no contiene polimorfismo virtual*/

	/*como no hay virtual, la única forma de que makeSound() de WrongCat
	se ejecute es accediendo al objeto a través de un puntero del mismo tipo
	(WrongCat*), no a través de un puntero a la base (WrongAnimal*).*/

	const	WrongCat* wrongCatDirect = new WrongCat();

	std::cout << WrongI->getType() << " " << std::endl;
	WrongI->makeSound();
	wrongMeta->makeSound();
	wrongCatDirect->makeSound();

	delete wrongCatDirect;
	delete wrongMeta;
	delete WrongI;

	return 0;
}