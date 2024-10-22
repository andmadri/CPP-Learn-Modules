#include "Account.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts{0};
int Account::_totalAmount{0};
int Account::_totalNbDeposits{0};
int Account::_totalNbWithdrawals{0};

Account::Account(int initial_deposit)
: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0), _accountIndex {_nbAccounts++}
{
    _totalAmount += _amount;
    _totalNbDeposits += _nbDeposits;
    _totalNbWithdrawals +=  _nbWithdrawals;
    std::stringstream s;
    _displayTimestamp();
    s << "index:" << _accountIndex << ";";
    s << "amount:" << _amount << ";created";
    std::cout << s.str() << std::endl;
}

Account::~Account(void){
    std::stringstream s;
    _displayTimestamp();
    s << "index:" << _accountIndex << ";";
    s << "amount:" << _amount << ";closed";
    std::cout << s.str() << std::endl;
}

int  Account::getNbAccounts(void){
    return _nbAccounts;
}

int  Account::getTotalAmount(void){
    return _totalAmount;
}

int  Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int  Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
    std::stringstream s;
    _displayTimestamp();
    s << "accounts:" << getNbAccounts() << ";";
    s << "total:" << getTotalAmount() << ";";
    s << "deposits:" << getNbDeposits() << ";";
    s << "withdrawals:" << getNbWithdrawals();
    std::cout << s.str() << std::endl;
}

void  Account::makeDeposit(int deposit){
    std::stringstream s;
    _displayTimestamp();
    s << "index:" << this->_accountIndex << ";"; 
    s << "p_amount:" << this->_amount << ";";
    s << "deposits:" << deposit << ";";
    this->_amount += deposit;
    _totalAmount += deposit;
    s << "amount:" << this->_amount << ";";
    this->_nbDeposits++;
    _totalNbDeposits++;
    s << "nb_deposits:" << this->_nbDeposits;
    std::cout << s.str() << std::endl;
}

bool  Account::makeWithdrawal(int withdrawal){
    std::stringstream s;
    _displayTimestamp();
    s << "index:" << this->_accountIndex << ";"; 
    s << "p_amount:" << this->_amount << ";";
    if (withdrawal > this->_amount) {
        s << "withdrawal:refused";
        std::cout << s.str() << std::endl;
        return false;
    }
    s << "withdrawal:" << withdrawal << ";";
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    s << "amount:" << this->_amount << ";";
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    s << "nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << s.str() << std::endl;
    return true;
}

int Account::checkAmount(void) const{
    return _amount;
}

void Account::displayStatus(void) const{
    std::stringstream s;
    s << "index:" << this->_accountIndex << ";"; 
    s << "amount:" << this->_amount << ";";
    s << "deposits:" << this->_nbDeposits << ";";
    s << "withdrawals:" << this->_nbWithdrawals << ";";
}

void Account::_displayTimestamp(void){
    std::time_t t = std::time(nullptr);
    std::tm* n = std::localtime(&t);
    std::cout << std::put_time(n , "[%Y%m%d_%H%M%S] ");
}
