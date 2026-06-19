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
	std::string newFile = _file + ".replace";

}