#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

// Character HEREDA de ICharacter
class Character : public ICharacter
{
	private:

		std::string _name;
		AMateria* _inventory[4]; // Aquí es donde vive el inventario de 4 slots


	public:

		// Constructor con nombre obligatorio
		Character(std::string const &name);
		
		// Forma Canónica Ortodoxa obligatoria para la clase concreta
		Character();
		Character(const Character &src);
		virtual ~Character(); // Hereda la virtualidad de la interfaz
		Character &operator=(const Character &src);

		// Implementación de los métodos virtuales puros de la interfaz
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif