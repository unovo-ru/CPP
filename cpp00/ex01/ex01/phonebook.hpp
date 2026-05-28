#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
	private:
		//el array de 8 objetos para no crear mas de los que se permiten
		Contact _contact[8];

		//variables para el control
		int		_i;				//index del contacto
		int		_totalContacts;	//para saber el numero de contactos guardados

	public:
		//CONSTRUCTOR: esta funcion o metodo se llama igual que la clase
		// su funcion es inicializar variables (poner _i a 0)
		// en el momento en el que se crea el objeto en el main
		PhoneBook();

		// los comandos que pide el subject
		void	addContact(void);
		void	searchContact(void);

};
#endif