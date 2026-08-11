#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	generator = displayNumber();

	if (generator == 0)
		return (new A());
	if (generator == 1)
		return (new B());
	else
		return (new C());
}
