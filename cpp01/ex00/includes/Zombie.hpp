
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //


/*COMO SE CUANDO LOS METODOS Y ATRIBUTOS SON PUBLICOS O PRIVADOS?

PRIVATE:	aqui va lo que no queremos que toque nadie desde fuera 
			programa, (no deberias abrir el telefono para acceder a la 
			bateria, solo deberias poder ver su estado desde los ajustes del 
			telefono)

			_name es privado porque no quiero que nadie cambie el nombre de
			los zombies sin pasar por los metodos que se deben emplear
			(los publicos)
			
			
PUBLIC:		(la pantalla y los botones del movil) elementos que se necesitan
			desde el exterior (como en el main) para interactuar con la maquinaria
			interna

			announce() debe ser publico porque el main necesita poder
			llamarla para que el zombie se auncie
*/

class Zombie
{

	private:

		std::string	_name;


	public:
	
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif