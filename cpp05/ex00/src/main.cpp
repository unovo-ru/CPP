#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	a("Test 1", 5);
	Bureaucrat	b(a);
	Bureaucrat	c;
	
	c = b;

	std::cout	<< a << std::endl;
	
	try
	{
		Bureaucrat	d("Test 2", 6798);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what()
					<< std::endl;
	}
	try
	{
		Bureaucrat	e("Test 3", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	f("Test 4", -89);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what()
					<< std::endl;
	}
	try
	{
		Bureaucrat	g("Test 5", 150);
		g.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what()
					<< std::endl;
	}
	try
	{
		Bureaucrat	h("Test 5", 1);
		h.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what()
					<< std::endl;
	}
}
