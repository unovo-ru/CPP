#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
			AForm("President", "", 25, 5)
{
	std::cout	<< "Default Costructor called"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
			AForm("President", target, 25, 5)
{
	std::cout	<< "Costructor called"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
			AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execAction(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}


