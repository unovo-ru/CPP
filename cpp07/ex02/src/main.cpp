#include "Iter.hpp"

int	main(void)
{
	std::string	miArray[] = {"AGUANTE BOQUITA", "hola mundo", "monociclo"};

	::iter(miArray, 3, ::printTpl<std::string>);
	return (0);
}