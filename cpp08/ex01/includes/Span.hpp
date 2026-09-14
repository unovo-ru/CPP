#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <list>


/*La alternativa natural aquí es un contenedor asociativo ordenado,
como std::multiset. La diferencia fundamental:

	-Un vector no sabe nada sobre el "valor" de lo que guarda; solo sabe posiciones.
	El orden lo decides tú al insertar (o lo cambias tú después con sort).

	-Un multiset mantiene automáticamente sus elementos ordenados por valor
	en todo momento — internamente es un árbol balanceado.
	Cada vez que insertas un elemento, él solo lo coloca en la posición correcta.
	A cambio, pierdes el acceso aleatorio por índice (no hay mi_multiset[3]) y
	las inserciones son O(log n) en vez de O(1) amortizado*/

class Span
{
	private:

		unsigned int	_N;


	public:

		Span();
		Span(unsigned int N);
		~Span();
		void	addNumber(unsigned int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		template<typename T>
		typename T::const_iterator	easyfind(const T &vec, int fnd)
		{
			typename T::const_iterator	it = std::find(vec.begin(), vec.end(), fnd);
			if (it == vec.end())
				throw NotFound("Error, not found");
			return (it);
		}
};




#endif