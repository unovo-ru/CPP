#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
// #include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		std::string	_target;


	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		virtual void	execAction(Bureaucrat const & executor) const;

		class ExecutionFailedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif