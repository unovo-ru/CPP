#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Intern::~Intern()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Intern	&Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	forms[3] = {"shrubbery creation",  "robotomy request", "presidential pardon"};
	int index = -1;
	for (int i = 0; i < 3; i++)
		if (forms[i] == formName)
			index = i;
	switch (index)
	{
		case 0:
		{
			std::cout	<< "Intern creates " << forms[0] << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		case 1:
		{
			std::cout	<< "Intern creates " << forms[1] << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:
		{
			std::cout	<< "Intern creates " << forms[2] << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		default:
		{
			std::cout	<< "Intern can't creates any form, incorrect Form Name"
						<< std::endl;
			break;
		}
	}
	return (NULL);
}
