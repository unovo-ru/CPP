#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
					AForm("Robotomy", "", 72, 45)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
					AForm("Robotomy", target, 72, 45)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
					AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm()
{
		std::cout	<< "Destructor called"
					<< std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::execAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout	<< "Drilling noise"
				<< std::endl;
	if (rand() % 2 == 0)
		std::cout	<< this->getTarget() << " has been robotomized successfully"
					<< std::endl;
	else
		std::cout	<< this->getTarget() << " robotomy failed."
					<< std::endl;
}

