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