#ifndef PHONEBOOK.HPP
# define PHONEBOOK.HPP

# include "Contact.hpp"

class PhoneBook
{
	private:

		//el array de 8 objetos 
		Contact		_contacts[8];

		//una funcion privada auxiliar para tomar el input
		sdt::string	_getInput(std::string prompt)	const;
		void		_displayShort(void)				const;
		void		_displayLong(void)				const;
		
		int			_i;
		int			_totalContacts;

	public:
	
		PhoneBook();		//constructor
		~PhoneBook();		//destructor

		void	addContact(void);
		void	searchContact(void);
};


#endif