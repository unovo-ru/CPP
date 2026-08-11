#include <iostream>
#include "TerminalStyles.h"
#include "Base.hpp"

int	displayNumber(void)
{
	time_t	now = time(NULL);
	int		numberGenered = now % 3;
	return (numberGenered);
}

int main(void)
{
	Base	*miBase = generate();

	identify(miBase);
	identify(*miBase);

	delete miBase;

	return 0;
}
