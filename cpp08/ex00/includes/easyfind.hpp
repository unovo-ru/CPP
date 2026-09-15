#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <list>

/*al tratabajr con templates recuerda pasarlo por referencias
para evitar hacer copias del dato, ya que pueden ser desde
un simple int a un array muy costoso en memoria*/

/*hacemos que el template tome el valor de un const_iterator
porque de esta forma no modificamos el contenido de lo que hay dentro
pero si podemos modificar el puntero, it++ / it--*/



/*EXCEPCIONES:*/

//1)

/*de esta forma generamos como hasta ahora excepciones estandares*/
// class NotFound : public std::exception
// {
// 	public:
// 		virtual const char	*what() const throw()
// 		{
// 			return ("ERROR. Data not found in container");
// 		}
// };



//2)

/*de esta forma podemos hacer una unica excepcion pero que lance distintos
mensajes segun nos convenga*/
// class NotFound : public std::exception
// {
// 	private:
// 		const char	*_message;

// 	public:
// 		NotFound(const char *message): _message(message){};
// 		virtual const char	*what() const throw()
// 		{
// 			return (_message);
// 		}
// };

class NotFound : public std::exception
{
	private:
		std::string	_message;

	public:
		NotFound(const std::string &message) : _message(message) {}
		virtual ~NotFound() throw() {}
		virtual const char	*what() const throw()
		{
			return (_message.c_str());
		}
};

template<typename T>
typename T::const_iterator	easyfind(const T &vec, int fnd)
{

	/*T se itera solo (mediante el find();) y busca el it por todo su recorrido
	y para cuando entramos en el if, donde ya tenemos un valor para it,
	que puede ser el de find o el de end(), de esta forma ya sabemos
	cual va a ser, y en el bucle lo hace find() por nosotros*/

	typename T::const_iterator	it = std::find(vec.begin(), vec.end(), fnd);
	if (it == vec.end())
		throw NotFound("Error, not found"); //AQUI ELEGIRIAMOS EL MENSAJE DEPENDIENDO
	return (it);							// DE LA EXCEPCION QUE QUERAMOS EXPONER
}

#endif