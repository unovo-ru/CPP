#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

// Character HEREDA de ICharacter
class Character : public ICharacter
{
	private:

		std::string		_name;
		AMateria		*_inventory[4]; // Aquí es donde vive el inventario de 4 slots
		/*si tengo en mis atributos un puntero a otra memoria
		esta debo deletearla en el destructor, no vale con una
		llamada al destructor sin mas */

	public:

		// Constructor con nombre obligatorio
		Character(std::string const &name);
		
		// Forma Canónica Ortodoxa obligatoria para la clase concreta
		Character();
		Character(const Character &src);
		virtual ~Character(); // Hereda la virtualidad de la interfaz
		Character &operator=(const Character &src);

		// Implementación de los métodos virtuales puros de la interfaz
		virtual std::string const	&getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

/*1. El mundo de las Materias (Habilidades)

	AMateria (La plantilla base): Es el concepto abstracto de "magia" o "energía". No puedes crear una AMateria a secas porque "la magia genérica" no existe en el juego; la magia tiene que ser de algo concreto.  

	Ice y Cure (Las habilidades reales): Estas son las magias concretas que el jugador puede lanzar. Son clases instanciables (puedes hacer new Ice() o new Cure()). Al heredar de AMateria, ambas comparten la estructura de tener un tipo y la capacidad de ser usadas.  */


#endif