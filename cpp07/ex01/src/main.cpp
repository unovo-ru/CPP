#include "Iter.hpp"

int	main(void)
{
	{
		std::string	miArray[] = {"AGUANTE BOQUITA", "hola mundo", "monociclo"};
	
		::iter(miArray, 3, ::printTpl<std::string>);
	}
	{
		int	miArray[] = {1, 2, 3, 4, 5};
	
		::iter(miArray, 3, ::printTpl<int>);
	}
	{
		double	miArray[] = {1.3, 7.5, 9.8, 0.3, 78.89};
	
		::iter(miArray, 3, ::printTpl<double>);
	}
	
	return (0);
}