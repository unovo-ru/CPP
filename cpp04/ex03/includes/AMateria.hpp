#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	private:
	protected:

		std::string	_type;

	public:

		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria &src);
		AMateria(std::string const & type);
		AMateria& operator=(const AMateria &src);
		std::string const& getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target) = 0;
};

#endif