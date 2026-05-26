#include "contact.hpp"

void	Contact::init(void)
{
	/*el "this->" es un equivalente en C al
	t_node->content. Es un puntero a la variable dentro del
	objeto, es opcional pero hace ver que estas tocando una
	variable dentro del objeto*/

	/*hay dos situaciones principales donde el this-> deja de ser
	opcional y se vuelve estrictamente obligatorio:

	A. Para evitar la colisión de nombres (Shadowing):
	Imagina que no hubieras usado la barra baja para tus
	atributos y tuvieras una variable llamada firstName.
	Si creas una función que recibe un parámetro con ese mismo
	nombre exacto, el compilador se confunde.
	
	B. Para devolver el propio objeto:
	Más adelante (sobre todo en el Módulo 02) verás que a veces una
	función necesita devolver el propio objeto entero para encadenar
	acciones. En C habrías hecho un return (t_node);.
	En C++, como this es el puntero al objeto, harás return *this;.*/

	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkSecret = "";
	do
	{
		std::cout << "Introduce First Name: ";
		std::getline(std::cin, _firstName);
		if (std::cin.eof())
			return ;
	} while (_firstName.empty());
	do
	{
		std::cout << "Introduce Last Name: ";
		std::getline(std::cin, _lastName);
		if (std::cin.eof())
			return ;
	} while (_lastName.empty());
	do
	{
		std::cout << "Introduce NickName: ";
		std::getline(std::cin, _nickName);
		if (std::cin.eof())
			return ;
	} while (_nickName.empty());
	do
	{
		std::cout << "Introduce Phone Number: ";
		std::getline(std::cin, _phoneNumber);
		if (std::cin.eof())
			return ;
	} while (_phoneNumber.empty());
	do
	{
		std::cout << "Introduce Dark Secret: ";
		std::getline(std::cin, _darkSecret);
		if (std::cin.eof())
			return ;
	} while (_darkSecret.empty());
}