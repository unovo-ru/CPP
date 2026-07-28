#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
				AForm("Shrubbery", "", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
				AForm("Shrubbery", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
				AForm(other) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

const char	*ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("File open failure\n");
}

void	ShrubberyCreationForm::execAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::string		fileName = this->getTarget() + "_shrubbery";
	std::ofstream	file(fileName.c_str()); // declaro un archivo con ofstream y lo abro con c_str()

	/*manejo el error de que posiblemente no se abra*/
	if (!file.is_open())
		throw ShrubberyCreationForm::FileCreationException();
	/*en caso de que no se abra TIRAMOS la excepcion que hemos desarrollado
	haciendo uso de throw y llamando a la clase a la que pertenece:

			FileCreationException dentro a su vez de ShrubberyCreationForm
			
			throw ShrubberyCreationForm::FileCreationException();*/
	file	<<	"               ,@@@@@@@,\n"
				"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
				"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
				"   ,%&\\%&&%&&%,@@@\\@@@/@@@ 8888888888)\n"
				"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
				"   %&&%/ %&%%&&@@\\ V /@@' `88\\8`/88'\n"
				"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
				"       |o|        | |         | |\n"
				"       |.|        | |         | |\n"
				"    \\\\/ ._\\_/__/  ,\\_//_\\\\/.  \\_//__/__\n";
	file.close();
}
