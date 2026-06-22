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

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif