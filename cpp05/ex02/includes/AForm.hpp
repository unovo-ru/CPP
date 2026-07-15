#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;

	public:

							AForm();
							AForm(const std::string name, const int toSign, const int toExec);
							AForm(const AForm &other);
		AForm&				operator=(const AForm &other);
		virtual				~AForm() {} ; //se virtualiza con las llaves

		const std::string	getName() const ;
		int					getGradeToSign() const ;
		int					getGradeToExec() const ;
		bool				getIsSigned() const ;

		void				beSigned(Bureaucrat const &bureaucrat);
		int					validateGrade(int grade);

		/*EXCEPCIONES*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		/*LA FUNCION QUE SERA ABSTRACTA PURA ES LA QUE NO PUEDE HACER LA CLASE MADRE
		(LA HACEN LAS HIJAS PORQUE ES PROPIO DE ELLAS), PERO QUE CADA HIJA NECESITA
		DE FORMA DISTINTA (ALGO ASI COMO LA QUE DA PASO A LA LLAMADA DE UNA EJECUCION
		PROPIA DE CADA UNA):
		
		
				execAction() --> (ejecuta una accion indeterminada (animal sound))
					|
					|-----> ShrubberyCreationForm --> imprimir un arbol ascii
					|
					|-----> RobotomyRequestForm ----> ruido de taladro
					|
					\-----> PresidentialPardonForm -> target perdondado
					
		*/
		virtual void		execAction(Bureaucrat const & executor) = 0;

		/*el metodo que cumple la revision de los requisitos para ver si se ejecuta la accion*/
		void				execute(Bureaucrat const & executor) const;
};
	
std::ostream	&operator<<(std::ostream &o, const AForm &other);

#endif