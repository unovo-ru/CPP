#ifndef BASE_HPP
#define BASE_HPP

class A;
class B;
class C;

class Base {
	public:
		virtual	~Base();
};

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);
int		displayNumber(void);

#endif

/*casteo dinamico:
es un casteo que elije en que forma transformarse en tiempo de ejecucion
de forma aleatoria, NO DURANTE LA COMPILACION

Mientras que el casteo estatico confia en lo que le digamos en la compilacion
el casteo dinamico comprueba si la conversion tiene sentido mirando el tipo real
del objeto, si lo tiene el casteo es completado, si no, suelta un aviso

NECESITA DEL POLIMORFISMO PARA EXISTIR:
necesitamos una etiqueta interna para poder hacer la comprobacion en
tiempo de ejecucion

el comportamiento segun puntero o referencia

	-CON PUNTERO:		si intentamos convertir Base* en A* y el objeto real no es A,
						el casteo dinamico devuelve un puntero NULL/0
						si en la comprobacion el puntero NO es NULL, el casteo funciono
					
	-CON REFERENCIA:	como la referencia no puede ser nula, si el cast falla
						no puede devolver nada, en su lugar lanza una excepcion
						la cual capturariamos con un try/cath*/