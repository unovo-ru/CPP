#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dataBase)
{
	/*para arbrir el archivo, creamos una variable de tipo ifstream
	usamos la variable que hace referencia al nombre del archivo (dataBase)
	y le pasamos c_str() */
	std::ifstream	db(dataBase.c_str());
	if (!db)
		throw Error("Error. could not open database file.\n");
	std::string	buffer;
	std::getline(db, buffer); 	//esto sirve para un descarte rapido de la
								//primera linea "date,exchange_rate"
	while (std::getline(db, buffer))
	{
		/*AÑADIR PARSEO:
		el dato tiene que estar bien ingresado y tiene un formato
		date,value*/
		size_t	dot = buffer.find(",");
		if (dot == std::string::npos)	//me aseguro de que si no encuentra la coma devuelva error
			throw Error("Error. Corrupted data base.\n");
		std::string	date = buffer.substr(0, dot);
		float	value = atof(buffer.substr(dot + 1, buffer.length() - (dot + 1)).c_str());
		_mapKey[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _mapKey(other._mapKey) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_mapKey = other._mapKey;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::parseFormat(const std::string &date)
{
	/*PARSEA EL FORMATO
	YYYY-MM-DD*/
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw Error("Error. Invalid format.\n");
	for (size_t i = 0; i < date.length(); i++)
		if (i != 4 && i != 7)
			if (!isdigit(date[i]))
				throw Error("Error. Invalid format in the date.\n");
		
}

void	BitcoinExchange::parseNumbers(const std::string &date)
{
	/*PARSEA QUE LOS NUMEROS SEAN VALIDOS*/
	std::string	y;
	std::string	m;
	std::string	d;

	for (int i = 0; i < 10; i++)
	{
		if (i < 4)
			y[i] = date[i];
		else if (i > 4 && i < 7)
			m[i] = date[i];
		else
			d[i] = date[i];
	}
	int year = atoi(y.c_str());
	int mouth = atoi(m.c_str());
	int day = atoi(d.c_str());
	if (year < )
}

void	BitcoinExchange::parseBitcoin(const std::string &value)
{
	/*PARSEA QUE PARA QUE LOS NUMEROS NO SE VAYAN DE MADRE
	NO HAYA NINGUNO IGUAL O MAYOR A 1000*/
}

void	BitcoinExchange::parseDate(const std::string &date)
{
	/*PARSEA QUE LAS FECHAS EXISTAN, NO SE ADMITEN VALORES
	MAYORES A 31, PERO TAMPOCO EN TODOS LOS CASOS PORQUE HAY MESES
	DE 30 DIAS, ASI COMO CONTEMPLAR EL MES DE FEBRERO Y LOS AÑOS BISIESTOS*/
}

float	BitcoinExchange::getRate(const std::string &date) const
{
	/*BUSCA POR FECHA EN LA BASE DE DATOS PARA SABER QUE RESULTADO DAR
	A LA COTIZACION DE ESE AÑO*/
}

void	BitcoinExchange::parse(const std::string &input)
{
	/*LLAMA A TODAS LAS DEMAS FUNCIONES DE PARSEO Y SEPARA POR LA
	PIPE ADEMAS DE ASEGURARSE DE QUE EL PINPUT RESPETA QUE LA PRIMERA
	LINEA SEA:
	
	date | value
	
	*/


}