#include "Contact.hpp"

//CONSTRUCTOR:
//crea limpios los objetos 

Contact::Contact()
{
	this->_firstName = "";			//	|						this->_firstName;
	this->_lastName = "";			//	|						this->_lastName;
	this->_nickName = "";			//	|	--> es igual que:	this->_nickName;
	this->_phoneNumber = "";		//	|						this->_phoneNumber;
	this->_darkSecret = "";			//	|						this->_darkSecret;
}

/*IMPLEMENTAMOS LOS SETTERS

	el "this->" es un equivalente en C al
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

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;		// es lo mismo que:	_firstName = firstName;
}
void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setLastName(std::string nickName)
{
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkSecret(std::string darkSecret)
{
	this->_darkSecret = darkSecret;
}

/*IMPLEMENTAMOS LOS GETTERS*/

/*std::string		Contact::	getFirstName		(void)			const
	|					|			|					|				|
devolvemos			tomamos		usamos el metodo	parametro		nos aseguramos
un objeto			el objeto	dentro del objeto	que le			de que no
con las cualidades	que hemos						introducimos	modifica ningun
de esta clase		creado											valor

"Soy una función llamada getLastName que no necesita recibir nada (void).
Pertenezco exclusivamente a la clase Contact::, prometo solemnemente no modificar nada
de mi objeto (const), y cuando termine, te entregaré un texto (std::string)."

*/

std::string		Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string		Contact::getLastName(void) const
{
	return (_lastName);
}

std::string		Contact::getNickName(void) const
{
	return (_nickName);
}

std::string		Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string		Contact::getDarkSecret(void) const
{
	return (_darkSecret);
}