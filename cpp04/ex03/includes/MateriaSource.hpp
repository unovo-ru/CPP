#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
class AMateria;

class MateriaSource: public IMateriaSource
{
	private:

		AMateria	*_learnedMaterias[4];


	public:

							MateriaSource();
							MateriaSource(const MateriaSource& src);
		MateriaSource&		operator=(const MateriaSource& src);
		virtual				~MateriaSource();

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
