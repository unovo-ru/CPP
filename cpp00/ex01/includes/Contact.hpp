#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkSecret;

	public:
		Contact();		//este es el constructor para inicializar
		~Contact();		//este es el destructor

		//SETTERS (aqui se guarda la informacion)
		void			setFirstName(std::string str);
		void			setLastName(std::string str);
		void			setNickName(std::string str);
		void			setPhoneNumber(std::string str);
		void			setDarkSecret(std::string str);

		//GETTERS (aqui solo leemos la informacion)
		std::string		getFirstName(void)		const;	//		|
		std::string		getLastName(void)		const;	//		|
		std::string		getNickName(void)		const;	//		|--> el const es para garantizar que no 
		std::string		getPhoneNumber(void)	const;	//		|	modificaremos la informacion (solo lee)
		std::string		getDarkSecret(void)		const;	//		|
};

#endif