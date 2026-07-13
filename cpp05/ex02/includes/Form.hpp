#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;

	public:

		Form();
		Form(const std::string name, const int toSign, const int toExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

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

	};
	
std::ostream	&operator<<(std::ostream &o, const Form &other);

#endif