#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout	<< "Error, invalid arguments."
					<< std::endl;
		return (0);
	}
	
	/*para este ejercicio vamos a usar estos 4 metodos:
	
		1.- std.find() --> DEDTECTA LAS POSICIONES
			busca una subcadena (s1 dentro de str)
			devuelve un numero (size_t) que es la posicion
			de la primera letra de la coincidencia
			
			(si no la encuentra devuelve std::string::npos
			que equivale a decir "no hay coincidencia").

			admite un segundo parametro para decirle de donde
			empezar a buscar str.find(s1, desde_donde_busco);
			
		2.- str.substr() --> RECORTA EL STRING
			crea un substring tomando solo la parte que nos interesa
			admite 2 parametros, el primero dice desde donde empieza
			el recorte y el segundo hasta donde llega

		3.- str.erase() --> BORRADOR
			se usa para eliminar un pedazo del string original
			acortando asi la cadena, admite 2 parametros:
			str.erase(posicion_s1, s1.length()); siendo el primero
			la posicion de inicio y el segundo siendo el final de
			la eliminacion
		
		4.-str.insert() --> INTERCALA
			introduce una cadena dentro de otra, moviendo y concatenando
			el texto para que cuadre (Introduce una string nueva en mitad de
			tu string original,empujando el resto de caracteres hacia la derecha
			sin machacar nada.):
			pj: "hola mundo" dentro de: "aguante boquita"

					"hola [aguante boquita] mundo"
			*/
			
	File	file(av[1], av[2], av[3]);
	int	fd;
}