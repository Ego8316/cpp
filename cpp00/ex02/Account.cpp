/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:00:42 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:48:52 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Static member initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Default constructor
Account::Account(void)
	:	_amount(0),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	return ;
}

// Constructor
Account::Account(int initial_deposit)
	:	_accountIndex(Account::_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created\n";
	return ;
}

// Destructor
Account::~Account(void)
{
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed\n";
}

// Getters
int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int	Account::getTotalAmount( void ) { return Account::_totalAmount; }
int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

//Private functions
void	Account::_displayTimestamp( void )
{
	std::time_t	time;
	std::tm		*ltm;

	time = std::time(0);
	ltm = std::localtime(&time);
	std::cout << "[" << 1900 + ltm->tm_year;
	if  (ltm->tm_mon < 9)
		std::cout << 0;
	std::cout << ltm->tm_mon + 1;
	if (ltm->tm_mday < 10)
		std::cout << 0;
	std::cout << ltm->tm_mday;
	std::cout << "_";
	if (ltm->tm_hour < 10)
		std::cout << 0;
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << 0;
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << 0;
	std::cout << ltm->tm_sec;
	std::cout << "] ";
}

// Public functions
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
 	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
	return ;
}