#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _inventory()
{
	std::cout	<< "Character constructor called"
				<< std::endl;
}

Character::Character() : _name(), _inventory()
{
	std::cout	<< "Character Default constructor called"
				<< std::endl;
}

Character::Character(const Character &src) : _name(src.getName())
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();

	/*la otra opcion es la siguiente:
	
	*this = src
	
	aplicando la llamada al operador de asignacion e igualando los atributos mediante
	ese metodo, mas sencillo y directo*/

	std::cout	<< "Character Copy constructor called"
				<< std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout	<< "Character Destructor called"
				<< std::endl;
}

Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		_name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}	/*Necesitamos una deep copy — igual que hicimos con Brain* en Dog.
		Para cada slot no nulo, debemos llamar a clone():*/
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		//AMateria	*tmp(_inventory[idx]);
		this->_inventory[idx] = NULL;
	
	/*no se debe perder la memoria, por eso creamos un
	temporal del mismo tipo en el que lo almacenamos
	pero como es void no hacemos nada con el asi que esa linea de 
	codigo la pondremos donde hagamos el llamado a esta funcion
	no aqui ya que esta funcion no retorna nada y no es la encargada
	de gestionar ese puntero*/
}

void	Character::use(int idx, ICharacter& target)
{

}
