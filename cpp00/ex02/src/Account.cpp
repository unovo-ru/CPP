#include "Account.hpp"
#include <iostream>
#include <ctime>

void	Account::_displayTimestamp(void)
{
	//calculamos el tiempo con la funcion time
	time_t	now = time(NULL);

	//esta estructura almacena el tiempo en otro formato
	//el formato lo sacamos con la funcion localtime()
	tm		*timelocal = localtime(&now);

	//declaramos un buffer en el que vamos a escribir 
	//la fecha con el nuevo formato
	char	buffer[20];

	//Formatear tiempo a cadena de texto). Su trabajo exacto es coger
	//los datos numéricos de una fecha (como "año: 92", "mes: 0", "día: 4")
	//y transformarlos en un texto ordenado


	//strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tiempo_local);
	//			|			|					|					|
	//			1			2					3					4
	//	destino donde	el tamaño que	formato que vamos	puntero a la estructura
	//	la funcion		va a escribir	a seguir			donde estan guardados
	//	escribe el		como mucho							los datos del tiempo
	//	texto

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timelocal);
	std::cout	<< buffer;
}

Account::Account(int initialDeposit)
{
	_amount = initialDeposit;	//el deposito con el que inicia el programa
	_nbDeposits = 0;			//variable que acaba de nacer (0)
	_nbWithdrawals = 0;			//variable que acaba de nacer (0)

	/*ahora vamos a asignar un index al cliente*/
	_accountIndex = _nbAccounts;	//este atributo es static, por tanto se inicia solo en 0

	/*tras esto hay que sumar uno al numero de cuentas totales que hay ene l banco*/
	_nbAccounts++;


	/*A CONTINUACION VA LO QUE SERIA EL PRIMER
	BLOQUE DEL LOG:
	
		_displayTimestamp()		sdd::cout
		(para la fecha)			(para escribir)

		[19920104_091532]		index:0;amount:42;created
		[19920104_091532]		index:1;amount:54;created
		[19920104_091532]		index:2;amount:957;created
		[19920104_091532]		index:3;amount:432;created
		[19920104_091532]		index:4;amount:1234;created
		[19920104_091532]		index:5;amount:0;created
		[19920104_091532]		index:6;amount:754;created
		[19920104_091532]		index:7;amount:16576;created
		[19920104_091532]		accounts:8;total:20049;deposits:0;withdrawals:0*/

	/*sumar el deposito que trae el cliente al dinero del banco*/
	_totalAmount += initialDeposit;

	/*ahora debemos tomar la fecha para que aparezca impresa en el log*/
	_displayTimestamp();	//hace falta hacerla primero!!!
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
}

//A CONTINUACION LOS GETTERS

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}


//LA SIGUIENTES FUNCIONES QUE APARECEN EN EL MAIN

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	
}