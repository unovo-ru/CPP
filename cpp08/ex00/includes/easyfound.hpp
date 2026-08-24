#ifndef EASYFINDER_HPP
#define EASYFINDER_HPP

#include <algorithm>
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

class NotFound : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("ERROR. Data not found in container");
		}
};

template<typename T>
typename T::const_iterator	easyFind(const T &vector, int find)
{

	/*T se itera solo (mediante el find();) y busca el it por todo su recorrido
	y para cuando entramos en el if ya tenemos un valor para it,
	que puede ser el de find o el de end(), de esta forma ya sabemos
	cual va a ser, y en el bucle lo hace find() por nosotros*/

	typename T::const_iterator	it = std::find(vector.begin(), vector.end(), find);
	if (it == vector.end())
		throw NotFound();
	return (it);
}

#endif