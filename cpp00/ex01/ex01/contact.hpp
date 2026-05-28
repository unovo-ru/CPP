#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>		/*para manejar los strings*/
# include <iostream>	/*manejar los flujos de entrada y salida*/
# include <iomanip>		/*manejo del espacio del string*/
class Contact
{
	private:
	/*aqui van las antiguas variables de los structs en C
	a las privadas se les suele poner (_) a las variables privadas
	para distinguirlas de las publicas*/

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkSecret;

	public:
	/*aqui van los metodos y variables que van expuestos
	ya no pasamos un t_contact a la funcion, el metodo ya sabe
	sobre que contacto opera*/

		void	init(void);					// metodo para pedir y guardar los 5 datos
		void	displayShort(int index);	// metodo para imprimir la fila de la tabla (con el pipe "|")
		void	displayFull(void);			// metodo para imprimir todos los detalles de ese contacto
};

#endif