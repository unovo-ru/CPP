#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T	min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif