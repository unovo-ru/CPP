# C++ Module 00 (42)

Este repositorio contiene el proyecto **CPP Module 00** de 42.

## Objetivo
Introducir los fundamentos de C++ con foco en:

- namespaces
- clases y métodos miembro
- `stdio` streams (`std::cout`, `std::cin`, etc.)
- listas de inicialización
- `static` y `const`

## Reglas importantes (Norma 42)

- `using namespace <ns_name>` está **prohibido**.
- `friend` está **prohibido**.
- No se permite STL (contenedores/algoritmos) hasta Módulos 08/09.
- Evitar fugas de memoria si se usa `new`.
- Cada header debe ser autosuficiente y con include guards.
- No implementar funciones en headers (excepto templates).

## Estructura del módulo

### ex00 — Megaphone
**Archivos requeridos:**
- `ex00/Makefile`
- `ex00/megaphone.cpp`

Programa que imprime los argumentos en mayúsculas.
Si no recibe argumentos, debe mostrar:

`* LOUD AND UNBEARABLE FEEDBACK NOISE *`

### ex01 — My Awesome PhoneBook
**Archivos requeridos:**
- `ex01/Makefile`
- `ex01/*.cpp`
- `ex01/*.{h,hpp}`

Clases obligatorias:
- `PhoneBook` (máximo 8 contactos, reemplazo circular del más antiguo)
- `Contact`

Comandos válidos:
- `ADD`
- `SEARCH`
- `EXIT`

Requisitos clave:
- Sin asignación dinámica para almacenar contactos.
- Campos de contacto no vacíos.
- Tabla de búsqueda con columnas de ancho 10 (`iomanip`), truncando con `.`.

### ex02 — The Job Of Your Dreams
**Archivos requeridos:**
- `ex02/Makefile`
- `ex02/Account.cpp`
- `ex02/Account.hpp`
- `ex02/tests.cpp`

Recrear `Account.cpp` para que `tests.cpp` compile y su salida coincida con el log esperado (salvo timestamps).

> Nota: ex02 no es obligatorio para aprobar el módulo.

## Compilación y uso
Cada ejercicio se compila dentro de su propio directorio:

```bash
cd ex00 && make
cd ex01 && make
cd ex02 && make
```

## Evaluación
- Solo se evalúa lo subido al repositorio.
- Durante la defensa pueden pedir una modificación breve del proyecto.

## Buenas prácticas recomendadas por 42
- Priorizar razonamiento propio antes de usar IA.
- Practicar peer-learning.
- Ser capaz de explicar cada decisión de implementación.
