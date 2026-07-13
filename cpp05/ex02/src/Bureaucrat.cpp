#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(), _grade(1)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout	<< "Assignation operator called"
				<< std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout	<< "Constructor called"
				<< std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
		//lanzamos la excepcion especifica en caso de error
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
		//lanzamos la excepcion especifica en caso de error
	_grade++;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other)
{
	o	<< other.getName()
		<< ", bureaucrat grade "
		<< other.getGrade()
		<< "." << std::endl;
	return (o);
}



/*throw() en la firma NO hace nada dentro del cuerpo de la función.
No participa en la lógica de lo que la función hace.
Es solo una promesa hacia el compilador "esta función garantiza
que ella misma no va a lanzar ninguna excepción".
Por eso está vacío () — significa "cero excepciones permitidas
de salir de aquí".*/

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, must be between 1 - 150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, must be between 1 - 150");
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout	<< *this << " signed "
					<< form
					<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout	<< *this << " couldn't sign "
					<< form
					<< "because " << e.what()
					<< std::endl;
	}
}