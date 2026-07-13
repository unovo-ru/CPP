#include "Form.hpp"

Form::Form() : _name(), _gradeToSign(1), _gradeToExec(1), _isSigned(false)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Form::Form(const std::string name, const int toSign, const int toExec):
	_name(name), _gradeToSign(validateGrade(toSign)), _gradeToExec(validateGrade(toExec)), _isSigned(false)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

Form::Form(const Form &other):
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec),
	_isSigned(other._isSigned)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout	<< "Assignation operator called"
				<< std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

const std::string	Form::getName() const
{
	return (_name);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, must be between 1 - 150");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, must be between 1 - 150");
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &o, const Form &other)
{
	o	<< other.getName()
		<< ", grade to sign: "
		<< other.getGradeToSign()
		<< " and grade to execute: "
		<< other.getGradeToExec();

	if (other.getIsSigned())
		o	<< "IS signed.";
	else
		o	<< "IS NOT signed.";
	return (o);
}

int	Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

