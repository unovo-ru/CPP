#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout	<< "Cure Deafault constructor called"
				<< std::endl;
}
Cure::~Cure()
{
	std::cout	<< "Cure Destructor called"
				<< std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout	<< "Cure Copy constructor called"
				<< std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout	<< "* heals "
				<< target.getName() << "'s wounds *"
				<< std::endl;
}
