#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <string>
#include <iostream>

template <typename T, typename F>
void	iter(T *array, int const size, F ft)
{
	for (int i = 0; i < size; i++)
		ft(array[i]);
}

template <typename T>
void	printTpl(T const &c)
{
	std::cout	<< c << std::endl;
}

#endif