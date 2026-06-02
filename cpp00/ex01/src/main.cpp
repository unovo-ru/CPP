#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	agenda;
	std::string	command;

	while (true)
	{
		std::cout	<< "Introduce instructions: ADD, SEARCH, EXIT:";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout	<< "CLOSING PHONEBOOK";
			break ;
		}
		if (command == "ADD")
			agenda.addContact();
		else if (command == "SEARCH")
			agenda.searchContact();
		else if (command == "EXIT")
			break;
		else if (command.empty())
			continue;
		else
			std::cout	<< "Invalid command"
						<< std::endl;
	}
	return (0);
}