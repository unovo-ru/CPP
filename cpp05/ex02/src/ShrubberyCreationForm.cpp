#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
				AForm("Shrubbery", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
				AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
				AForm(other), _target(other._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}


/*ME HE QUEDADO AQUI*/
void	ShrubberyCreationForm::execAction(Bureaucrat const &executor) const
{
	std::string		fileName = _target + "_shrubbery";
	std::ofstream	file(fileName.c_str());
}
