#include "Account.hpp"

#include <ctime>
#include <iostream>

//-----------------------------------------------------------------
// class public methods

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << "\n";
}

//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    ++_nbAccounts;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created\n";
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void) {
    --_nbAccounts;
    _totalAmount -= _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed\n";
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit) {
    if (deposit < 0)
        return;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";";
    _amount += deposit;
    _totalAmount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;
    std::cout << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << "\n";
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532]
// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";";
    if (withdrawal <= _amount) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        ++_nbWithdrawals;
        ++_totalNbWithdrawals;
        std::cout << "withdrawal:" << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << "\n";
        return true;
    }

    std::cout << "withdrawal:refused\n";
    return false;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << "\n";
}

// unused funcs in test.cpp
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
int Account::checkAmount(void) const { return _amount; }

//-----------------------------------------------------------------
// class private

// static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// class private methods

//[19920104_091532]
void Account::_displayTimestamp(void) {
    static const char* TIMESTAMP_FORMAT = "%Y%m%d_%H%M%S";
    static const std::size_t BUFFER_SIZE = 16;

    std::time_t currentTime = std::time(0);
    char timeBuffer[BUFFER_SIZE];

    std::strftime(timeBuffer, BUFFER_SIZE, TIMESTAMP_FORMAT,
        std::localtime(&currentTime));
    std::cout << "[" << timeBuffer << "] ";
}
