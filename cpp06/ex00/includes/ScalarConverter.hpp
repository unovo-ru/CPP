#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

/*tipos de casteo:

En C, para convertir tipos usabas el cast estilo C: (int)x, (float*)ptr, etc.
Es un cast "todopoderoso" pero peligroso: hace de todo (conversión numérica,
quitar const, reinterpretar bits, downcast entre punteros...)
sin decirte qué está pasando realmente ni avisarte si te equivocas.

C++ separa esa responsabilidad en 4 herramientas explícitas, cada una con una
intención clara:

	static_cast			→ conversiones "razonables" en tiempo de compilación
						(int↔float, upcast en jerarquías, etc.)
	
	dynamic_cast		→ conversión segura en tiempo de ejecución entre tipos
						polimórficos (necesita RTTI, o sea virtual)

	const_cast			→ añadir/quitar const (y nada más)

	reinterpret_cast	→ reinterpretar bits crudos, sin ninguna garantía de
						seguridad (ej. puntero ↔ entero)


Los tres ejercicios, en una frase cada uno

	ex00 (ScalarConverter):		conversión de tipos escalares (char/int/float/double)
								a partir de un string — pensado para static_cast.

	ex01 (Serializer):			convertir un puntero a un entero sin signo y viceversa,
								sin tocar ni interpretar los datos — pensado para
								reinterpret_cast.

	ex02 (Identify real type):	dado un Base* o Base&, averiguar el tipo dinámico
								real (A, B o C) sin usar
								typeid — pensado para dynamic_cast.

*/

class ScalarConverter
{
	private:	/*si todo lo pongo bajo la categoria de private no es necesario
				hacer la clase abstracta para hacerla ininstanciable*/

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		static void convert(const std::string);
};

#endif


/*
FROM python:3.12-slim
# Evita que Python genere archivos .pyc y fuerza salida sin buffer (mejor para logs)
ENV PYTHONDONTWRITEBYTECODE=1 \
    PYTHONUNBUFFERED=1
 
# Directorio de trabajo dentro del contenedor
WORKDIR /app
 
# Instala dependencias del sistema que suelen hacer falta (compilador, git, etc.)
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    curl \
    && rm -rf /var/lib/apt/lists/*
 
# Copiamos primero solo requirements para aprovechar la cache de Docker
COPY requirements.txt .
 
RUN pip install --no-cache-dir --upgrade pip \
    && pip install --no-cache-dir -r requirements.txt
 
# Ahora copiamos el resto del código
COPY . .
 
# Comando por defecto: abre una shell interactiva
CMD ["python3"]





comds:
docker build -t mi-proyecto-python .
docker run -it --rm -v $(pwd):/app mi-proyecto-python




librerias de python:
Requirements · TXT
# Añade aquí tus dependencias, por ejemplo:
# requests==2.32.3
# numpy==2.0.1
 
*/