#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	//CONSTRUCTOR Y ASSIGNATION OPERATOR
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	//TESTING OPERATORS
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	//TESTING EXCEPTIONS
	try
	{
		std::cout	<< "trying fill the value -2 -> 0, (expected: exception)\n";
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout	<< "trying fill the value 750 -> 0, (expected: exception)\n";
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout	<< "trying fill the value 749 -> 0, (expected: accepted)\n";
		numbers[MAX_VAL - 1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//GENERATING RANDOM NUMBERS AND COMPARING 
	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout	<< "GENERATING RANDOM NUMBERS AND COMPARING\n";
		if (numbers[i] != mirror[i])
		{
			std::cout	<< "numbers and mirrors aren't the same" << std::endl;
			break ;
		}
	}
	delete [] mirror;
	return 0;
}