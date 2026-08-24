#include "easyfound.hpp"

int	main()
{
	{
		std::vector<int>	vec;
		/*vec es un vector de ints vacio por el momento*/
		
		/*push_back añade al final del vector los datos que vamos
		pasandole:*/
		
		
		vec.push_back(3);
		/*vec = {3}*/
		vec.push_back(7);
		/*vec = {3, 7}*/
		vec.push_back(10);
		/*vec = {3, 7, 10}*/

		try
		{
			easyFind(vec, 4);
			std::cout	<< "FOUND: 4 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			easyFind(vec, 3);
			std::cout	<< "FOUND: 3 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		/*igual que en el ejemplo anterior pero lo aplicamos desde un array
		de ints tipico de C*/
		int					array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::vector<int>	arr(array, array + 10);

		try
		{
			easyFind(arr, 8);
			std::cout	<< "FOUND: 8 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			easyFind(arr, 81);
			std::cout	<< "FOUND: 81 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::list<int>	list;
		list.push_back(3);
		list.push_back(7);

		try
		{
			easyFind(list, 3);
			std::cout	<< "FOUND: 3 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			easyFind(list, 4);
			std::cout	<< "FOUND: 4 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			easyFind(list, 78);
			std::cout	<< "FOUND: 78 IS IN THE VECTOR"
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);

	/*PRA ESTE CASO NO FUNCIONA PORQUE LA PLANTILLA TEMPLATE NO
	RECONOCE EL ARRAY TIPICO DE C COMO UN OBJETO:
	
	EL COMPILADOR TRATA DE TRADUCIR EL TEMPLATE A PARTIR DEL ARGUMENTO:
	
	T = int[10]
	
	AQUI T NO ES UN CONTENEDOR DE NADA, ES SOLO UN ARRAY, NO PODEMOS DEVOLVER UN
	ITERADOR typename int[10]::const_iterator*/

	// {
	// 	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// 	try
	// 	{
	// 		easyFind(arr, 1);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
}