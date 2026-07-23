#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

		std::string	_target;


	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		std::string		getTarget() const;
		virtual void	execAction(Bureaucrat const & executor) const;

		class FileCreationException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif