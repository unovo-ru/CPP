#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef void (Harl::*harlFuntions)(void);	/*de esta forma lo que guarda es la
													direccion de memoria de debug, info...*/


		/*un puntero puede guardar la direccion de memoria de un dato, pero tambien
		puede apuntar a la direccion de memoria de una funcion, un puntero a una funcion
		almacena esa direccion de memoria.
		
		PARA QUE SIRVE?
		1.-	"Desacopla el codigo" evita tener que usar if/else pudiendo acceder a la funcion
			que se necesite sin estar pasando por todas las opciones, guardamos las funciones
			en una lista (array) y disparamos directamente la que necesitemos usando su posicion
			en el array
		
		2.-	como "callbacks", sirva para poder pasarle una funcion a otra funcion como si 
			fuera un parametro pj: una funcion que ordena, le podriamos decir:
			ORDENA ESTA LISTA DE MAYOR A MENOR, Y USA ESTA DIRECCION DE MEMORIA PARA ACCEDER
			A LA FUNCION QUE PERIMITE SABER CUAL ES MAYOR
			
		3.-	escalabilidad: si quisieramos añadir otro nivel en el futuro solo deberiamos
			añadir una funcion extra al array, sin tener que tocar la funcion complain*/

	public:
	
		Harl();
		~Harl();
	
		void complain( std::string level );
};

/*COMO DISTINGO CUANDO UNA FUNCION VA DENTRO O FUERA DEL OBJETO:

"¿Esta función NECESITA conocer o modificar las variables internas
(el estado) de un objeto concreto, o pertenece a la identidad de ese objeto?"

	VA DENTRO										VA FUERA

si defiende lo que el objeto es			si crea o gestiona objetos desde fuera
o lo que puede hacer					(newZombie, randomChump)

si necesita modificar atributos			si solo opera con los parametros que recibe
privados (_file, _name...)				y no le importa la vida interna de ninguna
										instancia (objeto)
*/


#endif