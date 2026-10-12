#include "PmergeMe.hpp"


/*
-	Un programa PmergeMe que recibe una secuencia de enteros positivos como argumentos.

-	Debe ordenarla con Ford-Johnson (merge-insertion sort).

-	Debe usar dos contenedores distintos, que no hayas usado en ex00 ni ex01,
	e implementar el algoritmo por separado para cada uno
	(el subject desaconseja una función genérica).

-	Debe mostrar: Before, After, y el tiempo de cada contenedor. 
	El tiempo debe incluir también la gestión de datos (rellenar el contenedor),
	no solo el ordenado.

-	Debe manejar como mínimo 3000 enteros y mostrar Error por stderr si
	la entrada no es válida (por ejemplo, negativos).
	Los duplicados los decides tú.*/


/*PARSEO:
DEBEN DAR Error (por stderr)

	-SIN ARGUMENTOS (./PmergeMe)
	-ARG VACÍO ("")
	-CUALQUIER CARÁCTER QUE NO SEA UN DÍGITO (letras, 12abc, 3.5, 1e3, 0x1F)
	-SIGNOS, TANTO -5 COMO +5 (*)
	-NEGATIVOS (incluido -0)
	-ESPACIOS DENTRO DE UN ARGUMENTO ("3 5") (*)
	-CERO (0, 000), porque "positivo" es estrictamente mayor que 0 (*)
	-MAYOR QUE INT_MAX (2147483648 en adelante)
	-DUPLICADOS (*)

DEBEN FUNCIONAR (sin Error)

	-UN SOLO NÚMERO (./PmergeMe 5): una secuencia de un elemento ya está ordenada
	-EXACTAMENTE INT_MAX (2147483647)
	-CEROS A LA IZQUIERDA (007 se interpreta como 7) (*)
	-NÚMEROS YA ORDENADOS, y ordenados a la inversa: pasan por todo el algoritmo, sin atajo
	-3000 NÚMEROS O MÁS (el caso shuf del subject)



FORMATO DE ENTRADA

	-ARGUMENTOS SEPARADOS COMO CASO PRINCIPAL (./PmergeMe 3 5 1)
	-SE VALIDA TODO ANTES DE EMPEZAR A MEDIR TIEMPOS
	-LOS ERRORES VAN A LA SALIDA DE ERRORES, NUNCA A LA ESTÁNDAR

*
Signos, ceros y espacios: mi recomendación es "solo dígitos" porque es la regla
más simple de explicar en una frase durante la defensa.

Cero: rechazarlo se apoya en la palabra "positivo" del subject.
Aceptarlo también sería defendible, pero tendrías que justificarlo.

Duplicados: el subject te deja libertad. Rechazarlos es lo más sencillo,
aunque Ford-Johnson funciona igual con ellos, así que aceptarlos también vale.
Lo importante es que puedas explicar tu elección.

Ceros a la izquierda: aceptarlos es lo que sale por defecto con "solo dígitos".
Si prefieres prohibirlos, es una comprobación más.
*/

PmergeMe::PmergeMe(): _vec(), _deq() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq){}

PmergeMe::PmergeMe(int ac, char **av)
{
	parseInput(ac, av);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}


void	PmergeMe::parseInput(int ac, char **av)
{
	if (ac < 2)
		throw Error("Error");
	for (int i = 1; i < ac; i++)
	{
		long int val = 0;
		if (!isValidNum(av[i], val))
			throw Error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
	hasDuplicates();
}

bool	PmergeMe::isValidNum(const std::string &str, long int &val)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	val = std::strtol(str.c_str(), NULL, 10);
	if (val <= 0 || val > INT_MAX)
		return (false);
	return (true);
}

void	PmergeMe::hasDuplicates() const
{
	if (_vec.size() <= 1)
		return ;
	std::vector<int> sortedCopy = _vec;
	std::sort(sortedCopy.begin(), sortedCopy.end());
	for (size_t i = 0; i + 1 < sortedCopy.size(); i++)
		if (sortedCopy[i] == sortedCopy[i + 1])
			throw Error("Error");
}

void	PmergeMe::printSequence() const
{
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout	<< _vec[i];
		if (i < _vec.size() - 1)
			std::cout	<< " ";
	}
	std::cout	<< std::endl;
}


void	PmergeMe::run()
{
	std::cout	<< "Before: ";
	printSequence();

	/*MEDICION EN VECTOR*/
	// -calcular el tiempo al incio (init)
	struct timeval initVec, endVec;
	gettimeofday(&initVec, NULL);
	
	// -algoritmo de ordenacion fordJohnson(_vec)
	
	// -calcular de nuvo el tiempo (endVec)
	gettimeofday(&endVec, NULL);
	double finalTimeVec = (endVec.tv_sec - initVec.tv_sec) * 1000000.0 + (endVec.tv_usec - initVec.tv_usec);
	std::cout	<< "After:  ";
	printSequence();

	/*MEDICION EN DEQUE*/
	struct timeval initDeq, endDeq;
	gettimeofday(&initDeq, NULL);
	
	// -algoritmo de ordenacion fordJohnson(_deq)
	
	gettimeofday(&endDeq, NULL);
	double finalTimeDeq = (endDeq.tv_sec - initDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - initDeq.tv_usec);

	//impresion de tiempos
	std::cout	<< "Time to process a range of " << _vec.size()
				<< " elements with std::vector : "
				<< finalTimeVec << " us"
				<< std::endl;
	std::cout	<< "Time to process a range of " << _deq.size()
				<< " elements with std::deque : "
				<< finalTimeDeq << " us"
				<< std::endl;

}

std::vector<size_t>	PmergeMe::buildInsertionOrder(size_t pendSize)
{
	/*función buildInsertionOrder(pendSize):
	crear vector de salida "orden"

	// Paso 1: Caso base
	si pendSize <= 1:
		devolver orden

	// Paso 2: Generar números de Jacobsthal suficientes
	crear lista "jacob"
	anterior = 1
	actual = 3

	mientras anterior < pendSize:
		añadir actual a "jacob"
		siguiente = actual + (2 * anterior)
		anterior = actual
		actual = siguiente

	// Paso 3: Construir el orden de índices hacia atrás
	ultimo_procesado = 1

	para cada valor J en "jacob":
		// Determinar el techo del bloque actual
		si J > pendSize:
			techo = pendSize
		si no:
			techo = J

		// Insertar en orden decreciente
		para k desde techo bajando hasta (ultimo_procesado + 1):
			añadir (k - 1) a "orden"

		ultimo_procesado = J
		si ultimo_procesado >= pendSize:
			terminar bucle

	devolver orden
*/
}