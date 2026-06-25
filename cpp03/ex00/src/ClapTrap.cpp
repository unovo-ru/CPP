#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout	<< "Constructor Default called"
				<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10),
_energyPoins(10) , _attackDamage(10)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	/*this es un puntero al objeto actual, o sea su tipo es ClapTrap*.
	Cuando el compilador ve return (*this) y el tipo de retorno es ClapTrap&,
	lo que ocurre es:

	*this → desreferencias el puntero, obtienes el objeto en sí
	El compilador lo recibe como ClapTrap& porque eso dice el tipo de
	retorno → automáticamente lo trata como referencia, no hace copia
	
	Es decir, *this te da el objeto, y el & del tipo de retorno le dice al compilador
	"devuelve esto como referencia, no copies nada".

	Si el tipo de retorno fuera ClapTrap sin &, sí haría una copia.
	El & en el tipo de retorno es lo que evita eso.*/

	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoins = other._energyPoins;
	_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	
}
void ClapTrap::takeDamage(unsigned int amount)
{

}
void ClapTrap::beRepaired(unsigned int amount)
{

}