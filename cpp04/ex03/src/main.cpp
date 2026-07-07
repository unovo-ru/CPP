
// #include "MateriaSource.hpp"
// #include "Character.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// int	main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice);
// 	src->learnMateria(new Cure);
// }


#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	// ====================================================
	// 1. CREACIÓN DE LA FUENTE DE MATERIAS (EL MOLDEADOR)
	// ====================================================
	// Creamos un MateriaSource en el heap utilizando un puntero de la interfaz IMateriaSource.
	// Esto nos permite usar el polimorfismo puro.
	IMateriaSource* src = new MateriaSource();

	// Le enseñamos a la fuente las materias reales pasándole instancias recién creadas.
	// Ahora 'src' se adueña de esta memoria y será responsable de borrar estos objetos 
	// concretos en su propio destructor.
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// =========================================================================
	// 2. CREACIÓN DE LOS PERSONAJES
	// =========================================================================
	// Instanciamos dos personajes concretos usando el puntero de la interfaz ICharacter.
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	// =========================================================================
	// 3. APRENDIZAJE Y EQUIPACIÓN DE HABILIDADES
	// =========================================================================
	AMateria* tmp;

	// Le pedimos a la fuente que busque una materia tipo "ice" en su catálogo.
	// Si la encuentra, 'createMateria' nos devolverá una copia totalmente nueva (un clon).
	tmp = src->createMateria("ice");
	// El personaje 'me' la equipa en su primer slot libre del inventario.
	me->equip(tmp);

	// Hacemos el mismo proceso para la materia de curación "cure".
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// =========================================================================
	// 4. ACCIÓN: USO DE LAS HABILIDADES
	// =========================================================================
	std::cout << "\n--- Inicio de los ataques/acciones ---" << std::endl;
	
	// Usamos el slot 0 (debe ser Ice) apuntando al objetivo 'bob'.
	// Se activará por polimorfismo el método 'use' de la clase Ice.
	me->use(0, *bob);
	
	// Usamos el slot 1 (debe ser Cure) apuntando al objetivo 'bob'.
	// Se activará el método 'use' de la clase Cure.
	me->use(1, *bob);

	std::cout << "--- Fin de las acciones ---\n" << std::endl;

	// =========================================================================
	// 5. LIMPIEZA TOTAL DE MEMORIA (EVITAR LEAKS)
	// =========================================================================
	// Al eliminar a 'bob', se ejecuta el destructor de Character.
	delete bob;
	
	// Al eliminar a 'me', su destructor de Character se encargará de hacer 'delete'
	// a cada materia que tenga equipada dentro de su inventario.
	delete me;
	
	// Al eliminar a 'src', su destructor de MateriaSource se encargará de hacer 'delete'
	// a las materias originales ("moldes") que le enseñamos con learnMateria.
	delete src;

	return 0;
}