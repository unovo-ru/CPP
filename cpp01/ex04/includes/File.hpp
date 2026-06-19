#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class File
{
	private:

		std::string		_file;	//para guardar el nombre del archivo .txt
		std::string		_s1;	//aqui va la cadena que queremos reemplazar
		std::string		_s2;	//aqui va la cadena POR la que la queremos reemplazar


	public:

		File(std::string file, std::string s1, std::string s2);
		~File();

		void	replace();		// se podria hacer como 
								//void	replace(std::string file, std::string s1, std::string s2);
								//pero no es necesario porque de la forma en
								//que lo construimos el metodo sabra perfectamente
								//que hacer con que partes del objeto
};

#endif