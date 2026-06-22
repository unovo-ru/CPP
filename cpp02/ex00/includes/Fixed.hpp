#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

/*a partir de este punto es obligatorio el uso de la
FORMA CANONICA ORTODOXA, ls creacion de las clases llevaran
obligatoriamente:

	1.-	CONSTRUCTOR por defecto: para poder crear objetos
		vacios.

	2.-	CONSTRUCTOR DE COPIA: para poder crear un objeto
		identico a partir de uno existente

	3.-	OPERADOR DE ASIGNACION (operator=) para poder copiar
		datos de un objeto a otro que ya ha sido creado

	4.-	DESTRUCTOR: para liberar la memoria una vez completado
		el programa.*/

class Fixed
{
	private:

		int					_fixedPointValue;		//guarda el valor del numero en punto fijo.
		static const int	_fractionalBits ;		//guarda el numero de bits fraccionados
													//(siempre sera 8).

	public:

		//operadores, constructores y destructores
		
			//CONSTRUCTOR Y DESTRUCTOR
			Fixed();
			~Fixed();

			//CONTRUCTOR DE COPIA
			Fixed(const Fixed &other);	//asi se escribe un constructor de copia, pasando
										//por referencia el objeto que vamos a copiar
										//y garantizando que no se modificara el original,
										//por eso debe se pasa por referencia

			//OPERADOR DE ASIGNACION
			Fixed &operator=(const Fixed &other);		//Fixed & (al principio): Es el tipo
			//		||									de dato que devuelve la función.
			//		||									el operador = devuelve una referecia
			//		||									al objeto modificado, esto permite formar
			//     \||/									cadenas (a = b = c)
			//		\/
			// [operator=:] Es el nombre especial de la función.
			// Le dice a C++: "Cuando veas el signo = entre dos objetos Fixed,
			// ejecuta este bloque".

			// [const Fixed &other:] Igual que en la copia,
			// es el objeto de la derecha del signo igual, el cual nos vamos
			//a limitar a leer.

			//metodos propios de la clase
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

};

#endif