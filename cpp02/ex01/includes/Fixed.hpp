#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>	//necesario para la funcion que redondea [roundf();]


class Fixed
{
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits;

	public:

		//operadores, constructores y destructores
		
			//CONSTRUCTOR Y DESTRUCTOR
			Fixed();
			Fixed(int const raw);
			Fixed(float const dec);
			~Fixed();

			//CONTRUCTOR DE COPIA
			Fixed(const Fixed &other);

			//OPERADOR DE ASIGNACION
			Fixed &operator=(const Fixed &other);

			//metodos propios de la clase
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

			float	toFloat(void) const;
			int		toInt(void) const;
};

	/*NECESITAMOS DE UNA FUNCION AUXILIAR FUERA DE LA CLASE
	PARA RESOLVER NUEVAS SOBRECARGAS DE OPERADORES, EN ESTE CASO
	[<<] 


	ESTO ES PORQUE EL MAIN PIDE: 

		std::cout	<< "a is " << a << std::endl;
		
	Y NO SE PUEDE LANZAR UN COUT DE UN OBJETO ENTERO, POR ELLO
	NECESITAMOS "TRADUCIR" ESE OPERADOR COMO HACIAMOS CON EL [=]
	DE ESTA FORMA CUANDO VEAMOS QUE SE INTENTA LANZAR UN OBJETO
	POR PANTALLA, EL COMPILADOR LLAMA "EN SECRETO" A LA SIGUIENTE FUNCION
	
	(std::cout es una instancia de std::ostream por eso es lo que devuelve
	la funcion)*/

	std::ostream &operator<<(std::ostream &os, Fixed const &obj);
	
	/*TRABAJA DE LA SIGUIENTE FORMA:
		->	std::ostream &os se convierte en tu pantalla (std::cout)
		->	Fixed const &obj se convierte en tu objeto (a).
		
	¿Qué recibe? Recibe dos cosas por parámetro:
	una referencia al flujo de salida (std::ostream &os) a la izquierda,
	y una referencia constante a tu objeto (const Fixed &obj) a la derecha.
	
	¿Qué hace dentro? Utiliza la función de conversión que ya programamos
	(toFloat()) para mandar el valor decimal al flujo os.
	
	¿Qué devuelve? Devuelve la misma referencia al flujo (return os;).
	Esto es vital para poder encadenar varias flechas seguidas,
	como haces al poner << a << std::endl;.*/


#endif