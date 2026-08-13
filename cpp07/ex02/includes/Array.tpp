#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/*esto dice que lo que estoy declarando es una funcion de la clase
Array con la variable T (template) como su variable principal*/

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &miArray)
{
	_data = new T[miArray._size];
	_size = miArray._size;
	for (unsigned int i = 0; i < miArray._size; i++)
		this->_data[i] = miArray._data[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &miArray)
{
	if (this != &miArray)
	{
		if (_data)
			delete[] _data;
		_data = new T[miArray._size];
		_size = miArray._size;
		for (unsigned int i = 0; i < miArray._size; i++)
			this->_data[i] = miArray._data[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index > _size - 1)
		throw (Array<T>::OutOfBoundsException());
	return (_data[index]);
}

template <typename T>
Array<T>::~Array()
{
	if (_data)
		delete[] _data;
}

template <typename T>
unsigned int	Array<T>::size()const
{
	return (_size);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Not avaiable, index bigger than the size");
}


#endif