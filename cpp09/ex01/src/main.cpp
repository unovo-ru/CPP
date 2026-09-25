#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr	<< "Error, could not open file.\n", 1);
	try
	{
		BitcoinExchange btc = BitcoinExchange("data.csv");
		std::ifstream	input(av[1]);
		if (!input.is_open())
			return (std::cerr	<< "Error, could not open file.\n", 1);
		std::string	line;
		getline(input, line);
		while (getline(input, line))
		{
			try
			{
				btc.parse(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}