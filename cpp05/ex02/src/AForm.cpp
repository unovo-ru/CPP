#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(), _gradeToSign(1), _gradeToExec(1), _isSigned(false)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

AForm::AForm(const std::string name, const int toSign, const int toExec):
	_name(name), _gradeToSign(validateGrade(toSign)), _gradeToExec(validateGrade(toExec)), _isSigned(false)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

AForm::AForm(const AForm &other):
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec),
	_isSigned(other._isSigned)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout	<< "Assignation operator called"
				<< std::endl;
	return (*this);
}

/*no necesito un destructor para una clase que a partir de ahora es abstracta*/
// AForm::~AForm()
// {
// 	std::cout	<< "Destructor called"
// 				<< std::endl;
// }

const std::string	AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, must be between 1 - 150");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, must be between 1 - 150");
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &o, const AForm &other)
{
	o	<< other.getName()
		<< ", grade to sign: "
		<< other.getGradeToSign()
		<< " and grade to execute: "
		<< other.getGradeToExec();

	if (other.getIsSigned())
		o	<< " IS signed.";
	else
		o	<< " IS NOT signed.";
	return (o);
}

int	AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("the form is NOT signed");
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (this->_gradeToExec < executor.getGrade())
		throw GradeTooLowException();
	/*mediante polimorfismo podemos llamar a la funcion que ejecuta aunque desde
	AForm es virtual pura, pero como en las hijas estara presente podemos hacer algo
	similar a declarar un AAnimal y darle el valor de un hijo instanciable:
	
		AAnimal *d = new Dog();
	
	en funcion del tipo de dato que trabajemos en el main, execAction(executor)
	sabra que tipo de hijo es: si shubbery, pardon...*/
	this->execAction(executor);
}
