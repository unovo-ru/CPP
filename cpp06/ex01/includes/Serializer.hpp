#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
	std::string	_name;	//los datos son irrelevantes para el ejercicio
	int			_age;
};

class Serializer
{
	private:

		Serializer();
		~Serializer();
		Serializer(const Serializer &miData);
		Serializer	&operator=(const Serializer &miData);


	public:

		static uintptr_t	serialize(Data* ptr);
		/*toma la direccion de memoria donde reside Data
		y lo reinterpreta como un numero entero y sin signo
		no modifica los datos de dentro, toma el valor de la direccion
		y lo pasa a un numero entero*/

		static Data*		deserialize(uintptr_t raw);
		/*hace el proceso contrario, toma el valor numerico y lo
		pasa a puntero con direccion de memoria a la estructura Data*/
};

#endif