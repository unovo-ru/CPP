#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void	testSubject()
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
	src->learnMateria(new Ice);
	src->learnMateria(new Cure);

	// =========================================================================
	// 2. CREACIÓN DE LOS PERSONAJES
	// =========================================================================
	// Instanciamos dos personajes concretos usando el puntero de la interfaz ICharacter.
	ICharacter* bob = new Character("bob");
	ICharacter* rob = new Character("rob");


	// =========================================================================
	// 3. APRENDIZAJE Y EQUIPACIÓN DE HABILIDADES
	// =========================================================================
	AMateria	*tmp;

	// Le pedimos a la fuente que busque una materia tipo "ice" en su catálogo.
	// Si la encuentra, 'createMateria' nos devolverá una copia totalmente nueva (un clon).
	tmp = src->createMateria("ice");
	// El personaje 'me' la equipa en su primer slot libre del inventario.
	bob->equip(tmp);

	// Hacemos el mismo proceso para la materia de curación "cure".
	tmp = src->createMateria("cure");
	rob->equip(tmp);

	// =========================================================================
	// 4. ACCIÓN: USO DE LAS HABILIDADES
	// =========================================================================

	
	// Usamos el slot 0 (debe ser Ice) apuntando al objetivo 'bob'.
	// Se activará por polimorfismo el método 'use' de la clase Ice.
	bob->use(0, *rob);
	rob->use(1, *bob);
	
	// Usamos el slot 1 (debe ser Cure) apuntando al objetivo 'bob'.
	// Se activará el método 'use' de la clase Cure.


	// =========================================================================
	// 5. LIMPIEZA TOTAL DE MEMORIA (EVITAR LEAKS)
	// =========================================================================
	// Al eliminar a 'bob', se ejecuta el destructor de Character.
	delete bob;
	
	// Al eliminar a 'rob', su destructor de Character se encargará de hacer 'delete'
	// a cada materia que tenga equipada dentro de su inventario.
	delete rob;

	// Al eliminar a 'src', su destructor de MateriaSource se encargará de hacer 'delete'
	// a las materias originales ("moldes") que le enseñamos con learnMateria.
	delete src;
}

void	fullInventoryTest()
{

	/*Si intentamos equipar una 5ª materia a un personaje,
	no explote el programa ni corrompa la memoria.
	Además, hay que vigilar qué pasa con la memoria de esa 5ª
	materia para que no se quede flotando*/

	std::cout	<< "-------TEST FULL INVENTORY-------"
				<< std::endl;

	ICharacter		*warrior = new Character("warrior");
	IMateriaSource	*inventory = new MateriaSource();

	inventory->learnMateria(new Ice);
	for (int i = 0; i < 5; i++)
	{
		AMateria	*tmp = inventory->createMateria("ice");
		if (i == 4)
		{
			std::cout	<< "[TEST] trying to equip 5th weapon... deleting extra"
						<< std::endl;
			delete tmp;
		}
		else
			warrior->equip(tmp);
	}
	std::cout << "[Test] Using slot 0:" << std::endl;
	ICharacter *target = new Character("target");
	warrior->use(0, *target);
	std::cout	<< "[Test] cleaning memory fullInventoryTest..."
				<< std::endl;
	delete target;
	delete warrior;
	delete inventory;
	std::cout << "------- FIN TEST: FULL INVENTORY -------\n" << std::endl;
}

void	deepCopyTest()
{
	std::cout	<< "\n--- TEST: DEEP COPY CHARACTER ---"
				<< std::endl;

	// 1. Creamos el generador y le enseñamos Hielo
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	// 2. Creamos al guerrero original
	// (usamos Character directo para facilitar la copia)
	Character* warrior1 = new Character("warrior 1");

	// Le equipamos una materia
	AMateria* iceMateria = src->createMateria("ice");
	warrior1->equip(iceMateria);

	// 3. ¡AQUÍ SE INCOPORA EL CONSTRUCTOR DE COPIA!
	// Creamos warrior2 pasándole el contenido desreferenciado (*warrior1)
	Character* warrior2 = new Character(*warrior1);

	// 4. PROBAMOS QUE LA COPIA ES PROFUNDA
	// Vamos a desequipar al warrior1 original.
	// Ojo: unequip() no borra la materia, solo la suelta, así que la guardamos para borrarla a mano.
	AMateria* iceWarrior = iceMateria; 
	warrior1->unequip(0);
	delete iceWarrior; // El slot 0 de warrior1 ahora está completamente vacío y destruido

	// 5. COMPROBACIÓN
	// Si la copia fue profunda, warrior2 copió la materia usando clone() en su constructor de copia.
	// Por lo tanto, warrior2 debería seguir teniendo su propio Ice intacto en el slot 0.
	std::cout	<< "[Test] Warrior1 (original) tries to attack:"
				<< std::endl;
	ICharacter* bob = new Character("Bob");
	warrior1->use(0, *bob);	// No debería hacer nada (slot vacío)

	std::cout	<< "[Test] Warrior2 (COPY) tries to attack:"
				<< std::endl;
	warrior2->use(0, *bob);	// Debería disparar el Ice perfectamente

	// ================
	// LIMPIEZA TOTAL
	// ================
	delete bob;
	delete warrior1;
	delete warrior2;
	delete src;
		
	std::cout << "--- FIN TEST: DEEP COPY CHARACTER ---\n" << std::endl;
}

int main()
{
	testSubject();
	fullInventoryTest();
	deepCopyTest();
	return (0);
}