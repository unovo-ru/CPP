/*TRABAJO CON CONTENEDORES:

std::vector

	Almacena los elementos en memoria contigua (como un array de C que se redimensiona solo).
	Acceso aleatorio en O(1): v[500] es tan rápido como v[0].
	Insertar/eliminar al final: O(1) amortizado (push_back).
	Insertar/eliminar en medio o al principio: O(n) — tiene que desplazar todos los elementos posteriores para hacer hueco o cerrar el hueco.
	Cuando se queda sin capacidad, reserva un bloque más grande y copia todo al nuevo sitio (esto es lo que hace que insertar en medio sea costoso, y también por qué a veces sus iteradores se invalidan tras una inserción).
	Su iterador es de acceso aleatorio (soporta <, +, [] sobre el propio iterador).

std::list

	Es una lista doblemente enlazada: cada elemento es un nodo independiente en memoria, con punteros al nodo anterior y siguiente.
	No hay acceso aleatorio: para llegar al elemento 500 tienes que recorrer uno a uno desde el principio (o el final) — O(n).
	Insertar/eliminar en cualquier posición es O(1), una vez tienes el iterador posicionado ahí — no hay que desplazar nada, solo enlazar/desenlazar punteros.
	Sus iteradores son bidireccionales (++/--, pero no < ni acceso por índice) — por eso en ex02 del módulo 08 tuviste que usar != en vez de <.
	Insertar no invalida iteradores existentes a otros elementos (a diferencia de vector).

Diferencia clave vector vs list: vector es rápido accediendo por posición pero caro insertando/eliminando en medio; list es justo lo contrario. Si tu algoritmo necesita "saltar" a posiciones concretas constantemente, vector gana; si necesita insertar/eliminar mucho en posiciones intermedias sin recorrer, list gana.
std::deque (double-ended queue)

	Es un intermedio interesante: por dentro suele implementarse como varios bloques de memoria contigua enlazados (no uno solo como vector).
	Acceso aleatorio en O(1) igual que vector (aunque con una constante algo mayor, por la indirección de bloques).
	Inserción/eliminación en ambos extremos (push_front y push_back) en O(1) — a diferencia de vector, que solo es O(1) eficiente por el final.
	Insertar/eliminar en medio sigue siendo O(n), igual que vector.
	Piensa en él como "un vector que también es barato insertar por delante".

std::set

	Contenedor asociativo ordenado que guarda claves únicas (sin duplicados), implementado típicamente como árbol balanceado (como el multiset que ya usaste en ex01 del módulo 08, pero sin permitir repetidos).
	Inserción, búsqueda y eliminación en O(log n).
	Se mantiene siempre ordenado automáticamente por valor.
	Iteradores bidireccionales, de solo lectura (no puedes modificar el valor de un elemento ya insertado, solo borrarlo/reinsertarlo, por la misma razón que vimos con multiset).

std::map

	Contenedor asociativo ordenado, igual que set, pero en vez de guardar valores sueltos guarda pares clave-valor (std::pair<Key, Value>), ordenado automáticamente por la clave.
	Búsqueda, inserción, eliminación por clave en O(log n).
	Muy útil cuando necesitas "buscar algo relacionado con una fecha/nombre/id" en vez de simplemente "buscar un número entre otros".
	Tiene un método muy relevante para lo que comentamos en ex00: lower_bound(clave), que te devuelve un iterador a la primera clave no menor que la que buscas — justo el tipo de operación que necesitas cuando tienes que encontrar "la fecha más cercana por debajo".

std::stack

	No es un contenedor real, es un adaptador (ya lo viste en el módulo 08): por dentro envuelve a otro contenedor (por defecto deque) y solo expone push/pop/top — comportamiento LIFO (último en entrar, primero en salir).
	No es iterable por defecto (por eso tuviste que "mutarlo" en el ejercicio anterior).


	
LA CONCLUSION LOGICA:

	ex00	(buscar la fecha más cercana por debajo en una base de datos fecha→valor),
			¿cuál de estos encaja mejor?

	ex01	(RPN, comportamiento LIFO de "coge los dos últimos"), ¿cuál usarías,
			sabiendo que stack ya lo usarás/descartarás en qué ejercicio?

	ex02	(Ford-Johnson, con acceso por posición y comparaciones constantes durante todo el
			algoritmo), ¿qué dos de los que queden libres después de tus elecciones en 1 y 2
			tienen más sentido, teniendo en cuenta lo que dijiste sobre "perder la esencia" de
			un contenedor ya ordenado?

	ex00	(Bitcoin Exchange)	→ std::map

	ex01	(RPN)				→ std::stack
	
	ex02	(PmergeMe)			→ std::vector + std::deque
*/


#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <cctype>

class RPN
{
	private:

	
	public:
	
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		class Error : public std::exception
		{
			private:

				std::string	_message;


			public:

				Error(const std::string &message) : _message(message) {}
				virtual ~Error() throw() {}
				virtual const char	*what() const throw()
				{
					return (_message.c_str());
				}
		};
};



#endif