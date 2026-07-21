#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	std::cout	<< "hola"
				<< std::endl;
	// 1. Form válido + impresión
	// Form	a("test1", 19, 10);
	// std::cout << a << std::endl;

	// // 2. toSign demasiado alto (>150)
	// try
	// {
	// 	Form	b("test2", 190, 10);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 3. toSign demasiado bajo (<1)
	// try
	// {
	// 	Form	c("test3", -5, 10);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 4. toExec demasiado alto (>150)
	// try
	// {
	// 	Form	d("test4", 19, 200);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 5. toExec demasiado bajo (<1)
	// try
	// {
	// 	Form	e("test5", 19, -3);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 6. Bureaucrat con grado suficiente firma correctamente
	// try
	// {
	// 	Bureaucrat	goodBureaucrat("Alice", 5);
	// 	a.beSigned(goodBureaucrat);
	// 	std::cout << a << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 7. Bureaucrat con grado insuficiente falla al firmar
	// try
	// {
	// 	Form		f("test6", 19, 10);
	// 	Bureaucrat	badBureaucrat("Bob", 50);
	// 	f.beSigned(badBureaucrat);
	// 	std::cout << f << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 8. Bureaucrat con grado suficiente usa signForm() con éxito
	// try
	// {
	// 	Form		formOk("formOk", 50, 30);
	// 	Bureaucrat	goodSigner("Charlie", 10);
	// 	goodSigner.signForm(formOk);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// // 9. Bureaucrat con grado insuficiente usa signForm() y falla
	// try
	// {
	// 	Form		formFail("formFail", 50, 30);
	// 	Bureaucrat	badSigner("Dave", 100);
	// 	badSigner.signForm(formFail);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	return (0);
}
