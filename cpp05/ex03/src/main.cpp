#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main()
{
	std::cout	<< "=== INTERN TEST ==="
				<< std::endl;
	
	std::cout	<< "--VALID FORMS--"
				<< std::endl;
	AForm	*a = Intern().makeForm("robotomy request", "Bender");
	AForm	*b = Intern().makeForm("shrubbery creation", "Yggdrassil");
	AForm	*c = Intern().makeForm("presidential pardon", "Bush");

	std::cout	<< "--INVALID FORMS--"
				<< std::endl;
	AForm	*d = Intern().makeForm("something else", "Nobody");

	std::cout	<< "signing and executing forms"
				<< std::endl;

	try
	{
		Bureaucrat	highRank("HighRank", 1);
		if (a)
		{
			highRank.signForm(*a);
			highRank.executeForm(*a);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	try
	{
		Bureaucrat	lowRank("LowRank", 150);
		if (b)
		{
			lowRank.signForm(*b);
			lowRank.executeForm(*b);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}