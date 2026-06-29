#include "ScavTrap.hpp"

/*el constructor de ClapTrap ya inicializa todos los atributos.
ScavTrap solo necesita llamarlo una vez para construir la base, y
luego dentro del cuerpo sobreescribir los valores
específicos de ScavTrap.*/

ScavTrap::ScavTrap() : ClapTrap()	//llamamos al constructor Default
{
	/*dentro sobreescribimos los valores que establece el inicializador
	default de Clap*/

	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "(SCAV) Constructor Default called"
				<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	//no hace falta asignar _name porque lo hace el propio constructor clap
	//_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "(SCAV) Constructor called"
				<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "(SCAV) Destructor called"
				<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	/*no hace falta hacer la copia porque la hace el llamamiento a clap*/
	std::cout	<< "(SCAV) Copy constructor called"
				<< std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	
	/*la llamada a la clase madre solo se hace en los constructores
	para el operador de asignacion se llama al metodo con la misma funcion
	de la clase madre*/
	ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap " << _name
				<< " is now in Gatekeeping mode!"
				<< std::endl;
}



/*IMPORTANTE, PARA NO IMPLEMENTAR LOS MISMOS MENSAJES DEL METODO PADRE (CLAP)
Y AUNQUE EXISTAN EN LA CLASE CLAP, LAS VOLVEMOS A DECLARAR Y DESARROLLAR PARA
QUE AL LLAMARLAS DESDE SCAV SE PRIORICE LA IMPLEMENTACION DEL MENSAJE PROPIO
DEL HIJO (SCAV)*/


void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout	<< "Scavtrap " << _name << " can't attack"
					<< std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout	<< "Scavtrap " << _name << " attacked at " << target
				<< " causing " << _attackDamage
				<< std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "ScavTrap "<< _name << " is alredy dead..."
					<< std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout	<< "Scavtrap " << _name << " took " << amount
				<< " points of damage! " << _hitPoints
				<< " HP remaining."
				<< std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "ScavTrap "<< _name << " is alredy dead..."
					<< " can't be repaired..."
					<< std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout	<< "ScavTrap "<< _name << " has no energy..."
					<< "can't be repaired..."
					<< std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout	<< "Scavtrap " << _name << " repaired " << amount
				<< " points of health! "
				<< std::endl << _hitPoints
				<< " HP remaining."
				<< std::endl << _energyPoints
				<< " energy points remaining."
				<< std::endl;
}