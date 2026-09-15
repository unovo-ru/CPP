#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>


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

		unsigned int		_N;
		std::multiset<int>	_span;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();
		void	addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template<typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			/*en caso de que me pasen un rango de numeros que supere el acotado
			por _N no pasa nada dado que addNumber ya parsea en cada llamado
			de forma interna*/
			while (begin != end)
			{
				this->addNumber(*begin);
				++begin;
			}
		}
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

/*METODOS UTILES SEGUN LA IA PARA MANEJAR EL CONTENEDOR:

1.- size_type	size() const;

	devuelve el numero de elementos que hay en el contendor actualmente
	
2.- iterator	insert(const value_type &val);

	añade un elemento al contenedor, a diferencia de push_back que lo pone
	al final aqui no se elige la posicion, tampoco es necesario ya que
	multiset funciona ordenando por el valor directamente, este metodo
	devuelve un iterador al elemento insertado
	
3.- begin() y end() funcionan igual que en vector, llevandote al primer y al
	ultimo elemento del contenedor, de forma que *begin() te devuelve el valor minimo
	y *end() te devuelve el ultimo lugar del container, pasado el ultimo valor
	
4.- rbegin() apunta al ultimo elemento y rend() al primero.
	
	son iteradores reversos recorriendo hacia atras, asi que *rbegin() nos devuelve
	el valor maximo sin necesidad de hacer el recorrido hacia atras --end(), lo cual
	es mas propenso a devolver errores de memoria al acceder a posibles alocaciones
	vacias*/


#endif