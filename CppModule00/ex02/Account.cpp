/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:51:19 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/25 12:48:47 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include <ctime>

#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET
			<< ";amount:" << BLUE << Account::checkAmount() << RESET
			<< ";created" << std::endl;

	Account::_nbAccounts++;
	Account::_totalAmount += Account::checkAmount();
}

Account::~Account(void)
{
	Account::_displayTimestamp();
    std::cout << "index:" << BLUE << this->_accountIndex << RESET
				<< ";amount:" << BLUE << this->_amount << RESET
				<< ";closed" << std::endl;

    Account::_nbAccounts--;
    Account::_totalAmount -= _amount;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	time_t rawTime;
	struct tm *timeinfo;
	char buffer[80];

	time(&rawTime);
	timeinfo = localtime(&rawTime);

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);

	std::cout << buffer;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << BLUE << Account::getNbAccounts() << RESET
			<< ";total:" << BLUE << Account::getTotalAmount() << RESET
			<< ";deposits:" << BLUE << Account::getNbDeposits() << RESET
			<< ";withdrawals:" << BLUE << Account::getNbWithdrawals() << RESET
			<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	if(deposit <= 0)
	{
		std::cout << ";deposit:refused" << std::endl;
		return ;
	}
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			<< ";p_amount:" << BLUE << Account::checkAmount() << RESET
			<< ";deposit:" << BLUE << deposit << RESET;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << BLUE << Account::checkAmount() << RESET
			<< ";nb_deposits:" << BLUE << this->_nbDeposits << RESET
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			<< ";p_amount:" << BLUE << Account::checkAmount() << RESET
			<< ";withdrawal:" << BLUE << withdrawal << RESET;

	if (Account::checkAmount() >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;

		std::cout << ";amount:" << BLUE << Account::checkAmount() << RESET
				<< ";nb_withdrawals:" << BLUE << this->_nbWithdrawals << RESET
				<< std::endl;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			<< ";amount:" << BLUE << Account::checkAmount() << RESET
			<< ";deposits:" << BLUE << this->_nbDeposits << RESET
			<< ";withdrawals:" << BLUE << this->_nbWithdrawals << RESET
			<< std::endl;
}
