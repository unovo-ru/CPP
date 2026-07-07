#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include <iostream>

class AMateria;

class IMateriaSource
{
	public:

		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

/*COMO SE TRATA DE UNA CLASE VIRTUAL PURA, (INTERFAZ)
NO NECESITA DE NINGUN CONSRTUCTOR, PERO ES OBLIGATORIO EL
USO DE DESTRUCTORES*/

#endif
