#include "TerminalStyles.h"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


void	identify(Base *p)
{

	A	*variableA = dynamic_cast<A*>(p);
	if (!variableA)
	{
		B	*variableB = dynamic_cast<B*>(p);
		if (!variableB)
		{
			C	*variableC = dynamic_cast<C*>(p);
			if (!variableC)
			{
				std::cout	<< RED << "Not possible to cast" << RST
							<< std::endl;
				return;
			}
			std::cout	<< BLUE << "C" << RST
						<< std::endl;
			return ;
		}
		std::cout	<< BLUE << "B" << RST
					<< std::endl;
	return ;
	}
	std::cout	<< BLUE << "A" << RST
				<< std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A variableA = dynamic_cast<A&>(p);
		std::cout << BLUE << "A" << RST << std::endl;
	}
	catch (std::exception &e1)
	{
		try
		{
			B variableB = dynamic_cast<B&>(p);
			std::cout << BLUE << "B" << RST << std::endl;
		}
		catch(const std::exception& e2)
		{
			try
			{
				C variableC = dynamic_cast<C&>(p);
				std::cout << BLUE << "C" << RST << std::endl;
			}
			catch(const std::exception& e3)
			{
				std::cerr << e3.what() << '\n';
			}
		}
	}
}
