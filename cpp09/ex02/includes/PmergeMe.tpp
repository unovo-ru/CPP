#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template<typename Container>
void	PmergeMe::fordJohnsonSort(Container &c)
{
	/*busqueda binaria de insercion de un elemento en un rango acotado
	de cadena principal*/

	// -------------------------------------------------------------
	// ETAPA 1: Caso Base
	// -------------------------------------------------------------
	// si c.size() < 2:
		// retornar (ya está ordenado)
	if (c.size() < 2)
		return ;


	// -------------------------------------------------------------
	// ETAPA 2: Gestión del impar (straggler) y Emparejamiento
	// -------------------------------------------------------------
	// tiene_impar = (c.size() % 2 != 0)
	// straggler = 0
	bool hasStraggler = (c.size() % 2 != 0);
	int straggler = 0;

	// si tiene_impar:
		// straggler = c.back()
		// eliminar último elemento de c
	if (hasStraggler)
	{
		straggler = c.back();
		c.pop_back();
	}

	// crear lista de pares "pairs" (std::vector< std::pair<int, int> >)
	//me permite usar los valores de a pares, se veia en el cpp00 ex02 (Account)
	
	/*HACER UN CONTAINER CON TEMPLATES, NO PUEDO USAR VECTOR SI DEBE FUNCIONAR TAMBIEN
	PARA DEQUE*/
	
	std::vector< std::pair<int, int> > pairs;

		
	// para i desde 0 hasta c.size() con paso de 2:
		// primero = c[i]
		// segundo = c[i + 1]
	for (size_t i = 0; i < c.size(); i += 2)
	{
		int first = c[i];
		int second = c[i + 1];
		if (first < second) //first: ganador, second: perdedor
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}


	// -------------------------------------------------------------
	// ETAPA 3: Ordenación recursiva de los ganadores
	// -------------------------------------------------------------
	// Creamos un contenedor temporal con solo los ganadores
	Container winners;

	// para cada par en pairs:
		// ganadores.push_back(par.first)
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);


	// Llamada recursiva: ordena los ganadores usando Ford-Johnson
	fordJohnsonSort(winners);


	// -------------------------------------------------------------
	// ETAPA 4: Reconstruir la asociación y preparar mainChain / pend
	// -------------------------------------------------------------
	Container mainChain;
	Container pend;

	// Por cada ganador ya ordenado, buscamos su pareja original en pairs
	for (size_t i = 0; i < winners.size(); i++)
	{
		// para que "pend" quede en el mismo orden que "mainChain"
		// para cada g en ganadores:
		int winner = winners[i];
		for (size_t j = 0; j < pairs.size(); j++)
		{
			// para cada par en pairs:
			// si par.first == g:
				// mainChain.push_back(g)
				// pend.push_back(par.second)
				// marcar par como usado (o eliminarlo de pairs) para evitar duplicados idénticos
				// romper bucle interno
			if (pairs[j].first == winner)
			{
				mainChain.push_back(winner);	//ganador va a la cadena principal
				pend.push_back(pairs[j].second);//perdedor va a la lista de pendientes
				//para mejorar el rendimiento de la busqueda deberiamos eliminar la pareja
				//una vez ha cumplido su funcion
				pairs.erase(pairs.begin() + j);//para saber cual eliminamos partimos del comienzo
				//y le sumamos la posicion de la pareja que ya hemos
				//separado y justo despues salimos
				break ;
			}
		}
	}


	// -------------------------------------------------------------
	// ETAPA 5: Inserción (Regla de b1 + Secuencia de Jacobsthal)
	// -------------------------------------------------------------
	
	
	// 1. Regla fija: b1 entra al principio de mainChain sin comparaciones
	if (!pend.empty())
		mainChain.insert(mainChain.begin(), pend[0]);

	// 2. Obtener el orden de Jacobsthal para el resto de perdedores
	std::vector<size_t> order = buildInsertionOrder(pend.size());

	// para cada idx en orden:
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i];
		// elemento_a_insertar = pend[idx]
		//localizar la posicion actual del ganador de la mainChain
		size_t maxSearchRange = 0;
		for (size_t k = 0; k < mainChain.size(); k++)
		{
			if (mainChain[k] == winners[idx])
			{
				maxSearchRange = k;
				break ;
			}
		}
		// pareja_ganadora = mainChain_asociada (o buscar dónde está su 'a_k' en mainChain)
		// El rango máximo de búsqueda es el índice donde está su ganador en mainChain
		// limite = posición de pareja_ganadora en mainChain
		binaryInsert(mainChain, pend[idx], maxSearchRange);
	}

	// 3. Insertar el impar (straggler) si existía
	// si tiene_impar:
	if (hasStraggler)
	{
		// No tiene pareja ganadora que lo limite: busca en toda la cadena principal
		binaryInsert(mainChain, straggler, mainChain.size());
	}

	// -------------------------------------------------------------
	// ETAPA 6: Volcar el resultado ordenado al contenedor original
	// -------------------------------------------------------------
	c = mainChain;
}

template<typename Container>
void	PmergeMe::binaryInsert(Container &mainChain, int element, size_t maxSearchRange)
{
	/*orquestador recursivo del algoritmo (empareja, ordena recursivamente
	los ganadores, construccion de pend (pendientes) e isercion usando a jacobsthal)*/
	size_t low = 0;
	size_t high = maxSearchRange;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (element < mainChain[mid])
			high = mid;
		else
			low = mid + 1;
	}
	mainChain.insert(mainChain.begin() + low, element);
}


#endif