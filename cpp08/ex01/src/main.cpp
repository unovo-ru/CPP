#include "Span.hpp"

int	main()
{
	/*SUBJECT EXAMPLE:*/
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	/*RANGE EXAMPLES*/
	{
		Span sp = Span(10000);

		/*CORRECT*/
		try
		{
			std::vector<int>	nums;
			for (int i = 0; i < 10000; i++)
				nums.push_back(i);
			sp.addRange(nums.begin(), nums.end());
			std::cout	<< sp.shortestSpan() << std::endl
						<< sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		/*INCORRECT (THE CONTAINER IS SMALLER THAN THE RANGE)*/
		try
		{
			std::vector<int>	nums;
			for (int i = 0; i < 19999; i++)
				nums.push_back(i);
			sp.addRange(nums.begin(), nums.end());
			std::cout	<< sp.shortestSpan() << std::endl
						<< sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}