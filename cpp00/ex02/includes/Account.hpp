// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account(void);

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;			// El número total de cuentas que existen en el banco
	static int	_totalAmount;			// La suma de todo el dinero de todos los clientes juntos
	static int	_totalNbDeposits;		// El total de ingresos
	static int	_totalNbWithdrawals;	// El total de retiradas

	static void	_displayTimestamp( void );

	int				_accountIndex;		// El número de identificación de esa cuenta concreta
	int				_amount;			// El dinero que tiene ese cliente en su cuenta
	int				_nbDeposits;		// Cuántos ingresos ha hecho este cliente
	int				_nbWithdrawals;		// Cuántas retiradas de dinero ha hecho este cliente

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */