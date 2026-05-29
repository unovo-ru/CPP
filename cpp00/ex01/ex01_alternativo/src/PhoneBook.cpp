#include "PhoneBook.hpp"

/*primero llamamos al constructor*/
PhoneBook::PhoneBook()
{
	_i = 0;
	
	/*no es necesario en cpp hacer un bucle 
	para inicializar todos los contactos*/
	_totalContacts = 0;

}
/*llamamos al destructor*/
PhoneBook::~PhoneBook(){};


/*metodo declarado para leer de forma segura*/
std::string		PhoneBook::_getInput(std::string prompt) const
{
	str::string	input = "";

	do
	{
		std::string << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (NULL);
		}
	} while (input.empty());
	return (input);
}

void	PhoneBook::addContact(void)
{
	//	creamos un objeto con los atributos y metodos
	//	de una clase std::string
	std::string	input;

	//	escribimos la peticion
	std::cout << "---AÑADIENDO UN NUEVO CONTACTO ---" << std::endl;
	
	//1.-	llamamos a nuestra funcion auxiliar para escribir por
	//		pantalla las peticiones

	//2-	igualamos nuestra variable[posicion] al resultad
	//		de llamar a cada uno de los setters

	input = _getInput("Introduce First Name: ");
	_contact[_i].setFirstName(input);
	input = _getInput("Introduce Last Name: ");
	_contact[_i].setLastName(input);
	input = _getInput("Introduce NickName: ");
	_contact[_i].setNickName(input);
	input = _getInput("Introduce Phone Number: ");
	_contact[_i].setPhoneNumber(input);
	input = _getInput("Introduce your Darkest Secret: ");
	_contact[_i].setDarkSecret(input);

	//	modificamos el valor de nuestro iterador
	_i = (_i + 1) % 8;
	if (_totalContacts < 8)
		_contact++;
}

void	PhoneBook::_disPlayShort(void)	const
{
	std::cout	<< std::setw(10) << "Index" << "|";
			<< std::setw(10) << "First Name" << "|";
			<< std::setw(10) << "Last Name" << "|";
			<< std::setw(10) << "NickName" << "|";

	for (int i = 0; i < _totalContacts; i++)
	{
		//declaramos las variables first, last, nick y les asignamos
		//los valores de los contactos pasandole los getters
		std::string		first = _contacts[i].getFirstName();
		std::string		last = _contacts[i].getLastName();
		std::string		nick = _contacts[i].getNickName();
		std::string << std::setw(10) << i << "|";

		if (first.length() > 10)
			std::cout		<< std::setw(10) << first.substr(0, 9) + ".";
		else
			std::cout		<< std::setw(10) << first;
		std::cout << "|";

		if (last.length() > 10)
			std::cout		<< std::setw(10) << last.substr(0, 9) + ".";
		else
			std::cout		<< std::setw(10) << last;
		std::cout << "|";
		
		if (nick.length() > 10)
			std::cout		<< std::setw(10) << nick.substr(0, 9) + "."
		else
			std::cout		<< std::setw(10) << nick;
		std::cout << "|";
	}
}

void	PhoneBook::searchContact(void)
{
	if (_totalContacts == 0)
	{
		std::cout "THE PHONEBOOK IS EMPTY";
		return ;
	}



}