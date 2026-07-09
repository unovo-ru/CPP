#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:

		std::string const	_name;


	public:

		Bureaucrat();
		Bureaucrat(std::string const name);
		~Bureaucrat();
};


#endif