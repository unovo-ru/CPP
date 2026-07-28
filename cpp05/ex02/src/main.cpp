#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main()
{
	{
		std::cout << "=== SHRUBBERY CREATION FORM ===" << std::endl;
		try
		{
			// 1. Crear burócratas con distintos rangos
			Bureaucrat lowRank("LowRankBob", 150);		// No puede firmar (150 > 145) ni ejecutar
			Bureaucrat midRank("MidRankAlice", 140);	// Puede firmar (140 <= 145), pero NO ejecutar (140 > 137)
			Bureaucrat highRank("HighRankCharlie", 1);	// Puede hacer todo

			// 2. Instanciar el formulario
			ShrubberyCreationForm shrub("jardin");

			// Intentar ejecutar sin estar firmado -> Debería fallar
			std::cout << "\n--- Intentando ejecutar sin firmar ---" << std::endl;
			highRank.executeForm(shrub);

			// Intentar firmar con rango insuficiente (150) -> Debería fallar
			std::cout << "\n--- Intentando firmar con rango insuficiente ---" << std::endl;
			lowRank.signForm(shrub);

			// Firmar con rango suficiente (140) -> Debería tener éxito
			std::cout << "\n--- Firmando con rango correcto ---" << std::endl;
			midRank.signForm(shrub);

			// Intentar ejecutar con rango insuficiente para ejecutar (140 > 137) -> Debería fallar
			std::cout << "\n--- Intentando ejecutar con rango insuficiente ---" << std::endl;
			midRank.executeForm(shrub);

			// Ejecutar con rango de sobra (1) -> Debería crear "jardin_shrubbery"
			std::cout << "\n--- Ejecutando con rango correcto ---" << std::endl;
			highRank.executeForm(shrub);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Excepción inesperada en main: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "=== ROBOT CREATION FORM ===" << std::endl; /*72, 45*/
		try
		{
			// 1. Crear burócratas con distintos rangos
			Bureaucrat lowRank("LowRankBob", 150);		// No puede firmar (150 > 145) ni ejecutar
			Bureaucrat midRank("MidRankAlice", 60);	// Puede firmar (140 <= 145), pero NO ejecutar (140 > 137)
			Bureaucrat highRank("HighRankCharlie", 1);	// Puede hacer todo

			// 2. Instanciar el formulario
			RobotomyRequestForm	robot("robot");
			// Intentar ejecutar sin estar firmado -> Debería fallar
			std::cout	<< "\ntrying to execute robot without sign\n";
			lowRank.executeForm(robot);

			// Intentar firmar con rango insuficiente (150) -> Debería fallar
			std::cout	<< "\ntrying to sign robot without grade enough\n";
			lowRank.signForm(robot);
			// Firmar con rango suficiente (140) -> Debería tener éxito
			std::cout	<< "\ntrying to sign robot with grade enough\n";
			midRank.signForm(robot);

			// Intentar ejecutar con rango insuficiente para ejecutar (140 > 137) -> Debería fallar
			std::cout	<< "\ntrying to execute robot without grade enough\n";
			midRank.executeForm(robot);

			// Ejecutar con rango de sobra (1) -> Debería crear "jardin_shrubbery"
			std::cout	<< "\ntrying to execute robot with grade enough\n";
			highRank.executeForm(robot);

		}
		catch (const std::exception &e)
		{
			std::cerr << "Excepción inesperada en main: " << e.what() << std::endl;
		}
	}

	{
				std::cout << "=== PRESIDENTIAL PARDON CREATION FORM ===" << std::endl; 
		try
		{
			// 1. Crear burócratas con distintos rangos
			Bureaucrat lowRank("LowRankBob", 150);		// No puede firmar (150 > 145) ni ejecutar
			Bureaucrat midRank("MidRankAlice", 20);	// Puede firmar (140 <= 145), pero NO ejecutar (140 > 137)
			Bureaucrat highRank("HighRankCharlie", 1);	// Puede hacer todo

			// 2. Instanciar el formulario
			PresidentialPardonForm	bush("bush");
			// Intentar ejecutar sin estar firmado -> Debería fallar
			std::cout	<< "\ntrying to execute bush without sign\n";
			lowRank.executeForm(bush);

			// Intentar firmar con rango insuficiente (150) -> Debería fallar
			std::cout	<< "\ntrying to sign bush without grade enough\n";
			lowRank.signForm(bush);
			// Firmar con rango suficiente (140) -> Debería tener éxito
			std::cout	<< "\ntrying to sign bush with grade enough\n";
			midRank.signForm(bush);

			// Intentar ejecutar con rango insuficiente para ejecutar (140 > 137) -> Debería fallar
			std::cout	<< "\ntrying to execute bush without grade enough\n";
			midRank.executeForm(bush);

			// Ejecutar con rango de sobra (1) -> Debería crear "jardin_shrubbery"
			std::cout	<< "\ntrying to execute bush with grade enough\n";
			highRank.executeForm(bush);

		}
		catch (const std::exception &e)
		{
			std::cerr << "Excepción inesperada en main: " << e.what() << std::endl;
		}
	}

	return (0);
}
