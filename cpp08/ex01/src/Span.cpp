#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span &other): _N(other._N), _span(other._span) {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_span = other._span;
	}
	return (*this);
}
Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_span.size() >= _N)
		throw Error("ERROR. The container is already full\n");
	_span.insert(n);
}
unsigned int	Span::shortestSpan() const
{
	if (_span.size() < 2)
		throw Error ("ERROR. There is no values enough in the container\n");
	

	/*Aquí no buscas "el mínimo y el máximo absolutos"
	buscas la menor diferencia entre vecinos, y esa pareja ganadora
	puede estar en cualquier punto de la secuencia.
	Con {3, 7, 9, 17} la pareja ganadora fue (7, 9), en medio;
	con otro conjunto de números podría estar al principio, al final,
	o en cualquier otro punto.
	No hay forma de saberlo sin comparar todas las parejas consecutivas
	entre sí, así que necesitas recorrer el contenedor entero comparando cada
	elemento con el siguiente, eso es lo que hace el while.
	Por eso esta operación es O(n):
	tienes que mirar cada elemento al menos una vez.*/

	/*por eso los pasos son:
	tomar dos iteradores para el primer valor y el inmediatamente siguente*/
	std::multiset<int>::const_iterator	current = _span.begin();
	std::multiset<int>::const_iterator	next = _span.begin();
	next++;

	/*tomar su diferencia como referencia*/
	unsigned int	shortest = *next - *current;
	
	while (next != _span.end())
	{
		/*ir iterando ambos comparando sus diferencias con la primera
		de referencia*/
		unsigned int	diff = *next - *current;
		/*de forma que si encontramos una menor la sobreescribimos en
		el valor que queremos devolver*/
		if (diff < shortest)
			shortest = diff;
		++current;
		++next;
	}
	return (shortest);
}
unsigned int	Span::longestSpan() const
{
	if (_span.size() < 2)
		throw Error ("ERROR. There is no values enough in the container\n");
	unsigned int max = *_span.rbegin();
	unsigned int min = *_span.begin();
	return (max - min);
}
