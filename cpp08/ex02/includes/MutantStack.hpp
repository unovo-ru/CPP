#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <string>
#include <iostream>
#include <list>


/*la clase creada debe ser tipo template para poder heredar de
std::stack<T> que tambien es de template y si tiene un iterador
propio:*/

/*lo que necesitamos replicar y que no viene por defecto con la herencia
son los siguientes comportamientos:

1.-	iterator y opcionalmente const_iterator
2.-	metodos begin() y end() y opcionalmente rbegin() y rend()
3.-	respetar y seguir la OCF*/

template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack	&operator=(MutantStack const &other);

		/*a continuacion le hacemos alias a los siguientes iteradores
		que se encuentran dentro de una ruta de varias clases dentro de otras.
		
		std::stack es un adaptador de contenedor, no uno en si mismo, para
		acceder al contenedor perteneciente que si tiene un iterador debemos hacer el
		siguiente recorrido:
		
			std::stack<T>::container_type::iterator

			contenedor iterator que pertenece a --> container_type que pertenece a
			--> stack<T> que a su vez pertenece a --> std

		ese es el recorrido que se necesita para acceder a los iteradores dentro de de stack<T>
		y para acortarlo vamos a hacer un alias:
		
		TYPEDEF TYPENAME std::stack<T>::container_type::iterator ---> iterator

		(de esta forma cuando el compilador vea "iterator" rapidamente leera el recorrido
		que hemos descrito arriba)
		
		A CONTINUACION AÑADIMOS TODOS LOS TIPOS DE ITERADORES A TRABAJAR:

		-ITERATOR
		-CONST_ITERATOR
		-REVEERSE_ITERATOR
		-CONST_REVERSE_ITERATOR*/
		
		typedef typename	std::stack<T>::container_type::iterator		iterator;
		typedef typename	std::stack<T>::container_type::const_iterator		const_iterator;
		typedef typename	std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename	std::stack<T>::container_type::const_reverse_iterator		const_reverse_iterator;


		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;


};

#include "../src/MutantStack.tpp"

#endif