#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
// #include "Bureaucrat.hpp"
class Bureaucrat;

/*cuándo forward declaration y cuándo #include completo

La regla es sobre qué necesita saber el compilador para procesar una línea
concreta de tu código:

	Si usas el tipo únicamente como referencia (Type &) o puntero (Type *)
	en una firma de función o como tipo de un parámetro — el compilador solo
	necesita saber que el nombre existe como clase, no cuánto ocupa en memoria
	ni qué miembros tiene. Una referencia/puntero siempre ocupa lo mismo
	(es básicamente una dirección de memoria), así que no necesita conocer los
	detalles internos de Bureaucrat para reservar espacio para
	Bureaucrat &. → te basta forward declaration.

	Si necesitas llamar a un método de ese tipo (objeto.getGrade()),
	acceder a un atributo, crear una instancia por valor (Bureaucrat b;, o tenerlo
	como atributo no-puntero de tu clase), o heredar de él — el compilador necesita
	conocer la definición completa: qué métodos tiene, qué tamaño ocupa,
	etc. → necesitas el #include completo.
*/

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		virtual void	execAction(Bureaucrat const & executor) const;
};

#endif