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

			bool	operator<(const Fixed &other) const;		//	
			bool	operator>(const Fixed &other) const;		//	
			bool	operator<=(const Fixed &other) const;		//	estas si van dentro de
			bool	operator>=(const Fixed &other) const;		//	la clase porque no devuelven
			bool	operator==(const Fixed &other) const;		//	un std::cout como el anterior
			bool	operator!=(const Fixed &other) const;		//	

			Fixed	operator+(const Fixed &other)const;			//
			Fixed	operator-(const Fixed &other)const;			//
			Fixed	operator/(const Fixed &other)const;			//
			Fixed	operator*(const Fixed &other)const;			//

			Fixed& operator--(void);	// los pre trabajan con void porque modifican
			Fixed& operator++(void);	// el objeto actual y lo devuelven por referencia

			Fixed& operator--(int);	//Para diferenciarlos de los anteriores, 
			Fixed& operator++(int);	//C++ exige que añadas un parámetro ficticio de tipo int en los paréntesis. 
										//Este int no sirve para pasarle ningún número, es solo una bandera
				/*ints como flags*/		//(un "flag") para decirle al compilador: "Oye, que este es el post-incremento".


			/*el static permite poder llamarlas sin crear un objeto:
			en tu main podrás usarlas sin necesidad de aplicarlas sobre una variable,
			llamándolas directamente así: Fixed::max(a, b).*/
			static const Fixed& min(const Fixed &a, const Fixed &b);
			static const Fixed& max(const Fixed &a, const Fixed &b);
			static Fixed & min(Fixed &a, Fixed &b);
			static Fixed & max(Fixed &a, Fixed &b);

};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif