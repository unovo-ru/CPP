#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
	private:

		T				*_data;
		unsigned int	_size;


	public:

						Array();
						Array(unsigned int n);
						Array(const Array &miArray);
		Array			&operator=(const Array &miArray);
		T				&operator[](unsigned int index);
						~Array();
		unsigned int	size()const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#include "Array.tpp"

#endif