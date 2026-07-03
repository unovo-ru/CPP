#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout	<< "\n\n---------------ARRAY---------------\n\n";

	Animal	*farm[4];
	farm[0] = new Dog();
	farm[1] = new Cat();
	farm[2] = new Dog();
	farm[3] = new Cat();

	std::cout	<< "\n\n---------------DOG---------------\n\n";

	Dog	*dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "I AM NO 1 DOG");

	Dog	*dog2 = new Dog(*dog1); //contructor de copia, le pasamos el que debe copiar

	// aquí ambos deberían tener "I AM N0 1 DOG"
	std::cout << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;

	//despues modificamnos la idea
	dog2->getBrain()->setIdea(0, "I AM NO 2 DOG");

	// aquí dog1 tiene "modified idea" pero dog2 debería seguir con "original idea"
	std::cout << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;

	std::cout	<< "\n\n---------------CAT---------------\n\n";

	Cat	*cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "I AM NO 1 CAT");
	Cat	*cat2 = new Cat(*cat1);
	std::cout << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << cat2->getBrain()->getIdea(0) << std::endl;
	cat2->getBrain()->setIdea(0, "I AM NO 2 CAT");
	std::cout << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << cat2->getBrain()->getIdea(0) << std::endl;

	std::cout	<< "\n\n---------------DELETE---------------\n\n";

	for (int i = 0; i < 4; i++)
		delete farm[i];
	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;

	return (0);
}