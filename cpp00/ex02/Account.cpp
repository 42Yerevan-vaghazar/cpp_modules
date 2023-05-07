#include "Account.hpp"
#include <iostream>


int	Account :: _nbAccounts;
int	Account :: _totalAmount;
int	Account :: _totalNbDeposits;
int	Account :: _totalNbWithdrawals;

int	Account :: getNbAccounts( void ) {
	return (_nbAccounts);
};

int	Account :: getTotalAmount( void ) {
	return (_totalAmount);
};

int	Account :: getNbDeposits( void ) {
	return (_totalNbDeposits);
};

int	Account :: getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
};

void Account :: displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

Account :: Account( int initial_deposit ) : _amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
	<< initial_deposit << ";created" << std::endl;
};

Account :: ~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
	<< _amount << "closed" << std::endl;
};

void Account :: makeDeposit( int deposit ) {
	++_totalNbDeposits;
	++_nbDeposits;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:"
	<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
};

bool Account ::	makeWithdrawal( int withdrawal ) {
	if (_amount < withdrawal) {
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	++_totalNbWithdrawals;
	++_nbWithdrawals;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:"
	<< withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbDeposits << std::endl;
	return (true);
};

int	Account ::	checkAmount( void ) const {
	return (_amount);
};

void Account ::	displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
};

void	Account :: _displayTimestamp( void ) {
	std::time_t t = std::time(0);
	struct tm  tstruct;
	char date_string[100];
	tstruct = *localtime(&t);
	std::strftime(date_string, 50, "[%Y%m%d_%H%M%S]", &tstruct);
	std::cout << date_string;
};