#include <cstdlib>
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
	std::string	input = "";
	bool			isAscii = false;

	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		isAscii = true;
		for (size_t i = 0; i < input.length(); i++)
		{
			if ((unsigned char)input[i] > 127)
			{
				std::cout	<< "Error, invalid Input"
							<< std::endl;
				isAscii = false;
				break ;
			}
		}
	} while (input.empty() || !isAscii);
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
	_contacts[_i].setFirstName(input);
	input = _getInput("Introduce Last Name: ");
	_contacts[_i].setLastName(input);
	input = _getInput("Introduce NickName: ");
	_contacts[_i].setNickName(input);
	input = _getInput("Introduce Phone Number: ");
	_contacts[_i].setPhoneNumber(input);
	input = _getInput("Introduce your Darkest Secret: ");
	_contacts[_i].setDarkSecret(input);

	//	modificamos el valor de nuestro iterador
	_i = (_i + 1) % 8;
	if (_totalContacts < 8)
		_totalContacts++;
}

void	PhoneBook::_displayShort(void)	const
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "NickName" << "|"
				<< std::endl;

	for (int i = 0; i < _totalContacts; i++)
	{
		//declaramos las variables first, last, nick y les asignamos
		//los valores de los contactos pasandole los getters
		std::string		first = _contacts[i].getFirstName();
		std::string		last = _contacts[i].getLastName();
		std::string		nick = _contacts[i].getNickName();
		std::cout		<< std::setw(10) << i << "|";

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
			std::cout		<< std::setw(10) << nick.substr(0, 9) + ".";
		else
			std::cout		<< std::setw(10) << nick;
		std::cout << std::endl;
	}
}

void	PhoneBook::_displayFull(int index) const
{
	//accedemos al array de _contacts y a la posicion dada por index
	//a continuacion accedemos a los getters publicos para
	//sacar la info

	std::cout	<< "First Name: " 
				<< this->_contacts[index].getFirstName()
				<< std::endl;

	std::cout	<< "Last Name: "
				<< this->_contacts[index].getLastName()
				<< std::endl;

	std::cout	<< "NickName: "
				<< this->_contacts[index].getNickName()
				<< std::endl;

	std::cout	<< "Phone Number: "
				<< this->_contacts[index].getPhoneNumber()
				<< std::endl;

	std::cout	<< "Darkest Secret: "
				<< this->_contacts[index].getDarkSecret()
				<< std::endl;
}

void	PhoneBook::searchContact(void)
{
	if (_totalContacts == 0)
	{
		std::cout	<< "THE PHONEBOOK IS EMPTY"
					<<std::endl;
		return ;
	}

	//aqui llamamos a la funcion privada para mostrar la tabla.
	this->_displayShort();

	//creamos 2 variables una tipo string para manejar el input que vamos 
	//a meter y otra para el indice con un valor numerico que sale de este
	//mismo input
	std::string	input;
	int			index;

	while (true)
	{
		//llamamos a getInput para que de las instrucciones y guardar
		//lo que escribamos en la variable input
		input = _getInput("introduce Index: ");

		//validamos que sea un unico caracter (un numero)
		//ademas tiene que estar entre 0 y el maximo de contactos permitidos
		if (input.length() == 1 &&  input[0] >= '0' && input[0] < ('0' + this->_totalContacts))
		{
			index = input[0] - '0';
			this->_displayFull(index);
			break ;
		}

		//en caso de que no sea asi lanzamos un mensaje de error
		else
		{
			std::cout	<< "Error: Invalid Index"
						<< (this->_totalContacts - 1)	// esto es porque tenemos como maximo
														//8 contactos pero son del 0 -7 asi que imprimimos
														//en base al numero que deberia tomar al introducirlo
														//en la agenda (por ejemplo el 6 sera el 5)
						<< "."
						<< std::endl;
		}
	}
}
