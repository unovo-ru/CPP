#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
// #include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		std::string const	_name;	// constante: el nombre no cambia tras la creación
		int					_grade;	// no const: debe poder incrementar/decrementar


	public:

		/*FORMA CANONICA ORTODOXA*/
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat();

		/*GETTERS*/
		std::string		getName() const;
		int				getGrade() const;
		/*MODIFICADORES DEL RANGO*/
		void			incrementGrade();
		void			decrementGrade();

		/*EXCEPCIONES ANIDADAS
		Heredan de std::exception para poder atraparse con catch(std::exception &e)
		No necesitan seguir la OCF (el subject lo exime explícitamente)*/

		/*se declara asi para indicar que estas funciones (metodos)
		solo existen dentro de Bureaucrat, no tienen sentido fuera de esta clase
		
		es como cuando en c guardabamos una estructura dentro de otra,
		de esta forma podemos crear una clase corta que tenga utilidad
		dentro de otra mayor, como en este caso con las excepciones:
		
		POR EJEMPLO:
		class LinkedList
		{
			private:							DENTRO DE LA CLASE LINKED
				class Node						DECLARA OTRA CLASE NODE EN LA QUE
				{								UNICAMENTE SE DECLARAN 2 ATRIBUTOS
					public:						Y CUANDO SALE DE ESTA COMO PARTE DE
						int data;				LA SECCION PRIVADA ALMACENA UN PUNTERO
						Node *next;				A UN ATRIBUTO QUE ES DEL MISMO TIPO
				};								QUE LA CLASE QUE HA DECLARADO
				Node *_head;
		};

		*/
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
		/*NUEVO METODO PERTENECIENTE A LA CLASE BUREAUCRAT PERO QUE RECIBE FORM*/
		void	signForm(AForm &form);
		
	};
	/*Operador de inserción como función LIBRE (no miembro):
	1.-	std::cout << bureaucrat  →  el operando izquierdo es ostream,
		no Bureaucrat
	2.-	No podemos usar friend (prohibido), así que accede a los datos
		vía getName()/getGrade()*/

	std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other);

#endif