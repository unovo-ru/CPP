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
	std::string	y = date.substr(0, 4);
	std::string	m = date.substr(5, 2);
	std::string	d = date.substr(8, 2);

	int year = atoi(y.c_str());
	int mounth = atoi(m.c_str());
	int day = atoi(d.c_str());
	if (mounth < 1 || mounth > 12)
		throw Error("Error. Mounth set incorrectly.\n");
	else if (day < 1 || day > 31)
		throw Error("Error. Day set incorrectly.\n");
	else {
		/*para este punto hemos barajado los dias y los meses
		necesito manejar los meses que sean de 1 - 30, 1 - 31 
		y 1 - 28/29 si es bisiesto*/
		switch (mounth) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				break;

			case 2:
				/*febrero, contemplar bisiestos y acotar a 28 en general*/
				if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
					if (day > 29)
						throw Error("Error. incorrect day.\n");
				}
				else
					if (day > 28)
						throw Error("Error. incorrect day.\n");
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30)
					throw Error("Error. Day setted incorrectly in this mounth.\n");
				break;

			default:
				break;
		}
	}
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