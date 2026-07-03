#include "AMateria.hpp"

AMateria::AMateria() : _type()
{
	std::cout	<< "AMateria Default constructor called"
			<< std::endl;
}

AMateria::~AMateria()
{
	std::cout	<< "AMateria Destructor called"
				<< std::endl;
}

AMateria::AMateria(const AMateria &src) : _type(src._type)
{
	std::cout	<< "AMateria copy contructor called"
				<< std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout	<< "AMateria contructor called"
				<< std::endl;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (_type);
}
