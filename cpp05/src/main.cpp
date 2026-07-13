#include "Bureaucrat.hpp"

int	main()
{
	/*Escribe el main.cpp de pruebas. El subject lo pide explícitamente
	("As usual, submit some tests to prove that everything works as expected").
	Como guía de qué casos deberías cubrir, piensa en:

	Crear un Bureaucrat válido y imprimirlo con <<
	Intentar crear uno con grade > 150 y capturar la excepción con try/catch
	Intentar crear uno con grade < 1
	Incrementar el grado hasta que llegue a 1 y ver que lanza excepción al querer subir más
	Decrementar hasta 150 y ver que lanza excepción al querer bajar más
	Probar el constructor de copia y el operator=
*/

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
