#include "File.hpp"

File::File(std::string file, std::string s1, std::string s2) :
_file(file), _s1(s1), _s2(s2) {}

File::~File()
{
	std::cout	<< _file << ": Eliminated correctly."
				<< std::endl;
}

void	File::replace()
{
	/*std::ifstream Abre una tubería que succiona los
	bytes de un archivo del disco duro hacia tu código.*/

	std::ifstream file(_file.c_str());		//este metodo dentro de esta clase
											//trata de abrir el archivo que 
											//corresponde al nombre guardado
											//en el atributo llamado (_file)
											//dentro del objeto declarado (file)


	//comprobamos a continuacion que el archivo se haya podido abrir
	if (!file.is_open())
	{
		std::cout	<< "Error: count not open input file: "
					<< _file
					<< std::endl;
		return ;
	}
	std::string newFile = _file + ".replace";			//creamos el nuevo nombre del archivo
	
	/*Abre una tubería para empujar datos desde
	tu programa y grabarlos en un archivo nuevo.*/
	std::ofstream replacedFile(newFile.c_str());		//abrimos el de escritura (replacedFile)
														//usando la misma funcion c_str
	
	//volvemos a comprobar que se haya abierto
	if (!replacedFile.is_open())
	{
		std::cout	<< "Error: count not open output file: "
					<< newFile
					<< std::endl;
		return ;
	}
	std::string	line;

	// Le pasamos 'file' (el stream), NO '_file' (el string con el nombre)
	// el stream es un flujo de entrada/salida de datos
	while (std::getline(file, line))
	{
		if (_s1.empty())							//
		{											//
			replacedFile << line << std::endl;		// AÑADIDO AHORA
			continue;								//
		}
		size_t pos = line.find(_s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, _s1.length());
			line.insert(pos, _s2);

			// para actualizar la posicion:
			// volvemos a llamar a find para encontrar la siguiente posicion
			// 1
			pos = line.find(_s1, pos + _s2.length());
		}
		replacedFile << line << std::endl;	//asi "volcamos" line en replacedFile
	}
	file.close();
	replacedFile.close();
}

/*FUNCION File::replace()
{
	1. INTENTAR abrir el archivo '_file' para lectura (usando std::ifstream).
	2. SI el archivo no se puede abrir (no existe o sin permisos):
		Mostrar error por pantalla y SALIR de la función.

	3. CREAR el nombre del archivo de salida concatenando '_file' + ".replace".
	4. INTENTAR abrir ese nuevo archivo para escritura (usando std::ofstream).
	5. SI no se puede crear/abrir:
		Mostrar error, cerrar el de lectura y SALIR.

	6. CREAR una variable 'std::string linea' para ir leyendo el archivo.
		
	7. MIENTRAS consigamos leer una línea del archivo original:
	{
		// Aquí dentro va tu lógica de la Estrategia A
		CREAR una variable 'posicion' y buscar la primera ocurrencia de '_s1' en 'linea'.
		
		MIENTRAS 'posicion' sea diferente a std::string::npos (es decir, mientras encuentre la palabra):
		{
			A.	BORRAR de 'linea' desde 'posicion' con la longitud de '_s1'.
			B.	INSERTAR '_s2' en 'linea' en esa misma 'posicion'.
			C.	ACTUALIZAR 'posicion': Volver a buscar '_s1' en 'linea', pero ¡OJO!
				Debes buscar DESDE donde termina tu nueva '_s2' para no quedarte en un bucle infinito si '_s2' contiene a '_s1'.
		}
		
		VOLCAR 'linea' en el archivo de salida (añadiendo el salto de línea).
	}

	8. CERRAR ambos archivos de forma limpia.
}*/