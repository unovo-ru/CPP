#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

// #include "AForm.hpp"

class Intern
{
	public:

		Intern();
		~Intern();
		Intern(Intern const &other);
		Intern	&operator=(Intern const &other);
		AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif