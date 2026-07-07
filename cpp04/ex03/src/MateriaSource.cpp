#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learnedMaterias()
{
	// Inicializamos explícitamente a NULL para evitar punteros basura
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
	std::cout	<< "MateriaSource Default constructor called"
				<< std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src): _learnedMaterias()
{
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
	*this = src;
	/*trabajando mediante la llamada del operador de asignacion*/
	std::cout	<< "MateriaSource constructor called"
				<< std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _learnedMaterias[i];
			if (src._learnedMaterias[i])
				_learnedMaterias[i] = src._learnedMaterias[i]->clone();
			else
				_learnedMaterias[i] = NULL;
		}
	}
	std::cout	<< "MateriaSource assignment operator called"
				<< std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_learnedMaterias[i])
			delete _learnedMaterias[i];
	std::cout	<< "MateriaSource Destructor called"
				<< std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_learnedMaterias[i])
		{
			_learnedMaterias[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_learnedMaterias[i])
			if (_learnedMaterias[i]->getType() == type)
				return (_learnedMaterias[i]->clone());
	return (NULL);
}
