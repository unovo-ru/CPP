#include "Dog.hpp"

using std::cout; using std::endl;

Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
	// _brain = new Brain();
	cout	<< "Default Dog constructor called"
			<< endl;
}
Dog::Dog(Dog const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	/*_brain(new Brain(*src._brain))
	asi creamos una copia profunda pero tomando como referencia
	el src del que queremos copiar*/

	// Animal::operator=(src);			es lo mismo que llamarlo dentro del cuerpo
	//									de la propia funcion
	cout	<< "Copy constructor Dog called"
			<< endl;
}
Dog& Dog::operator=(Dog const &src)
{
	if (this != &src)
	{
		delete _brain;
		/*delete _brain antes de _brain = new Brain(...)
		sin eso el Brain original que tenía
		this se queda huérfano en el heap.
		Memory leak garantizado.*/
		
		_brain = new Brain(*src._brain);


		/*delete _brain -> libera el Brain existente antes
		de sobreescribir el puntero
		
		*src._brain -> dereferencias el puntero para obtener el
		objeto Brain y pasárselo al constructor de copia de Brain*/
		Animal::operator=(src);
	}
	return (*this);
}

Dog::~Dog()
{
	cout	<< "Destructor Dog called"
			<< endl;
	delete _brain;
}
void	Dog::makeSound() const
{
	cout	<< "Wof wof...!!"
			<< endl;
}

Brain* Dog::getBrain() const
{
	return (this->_brain);
}