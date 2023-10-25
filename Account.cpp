#include "Account.hpp"

    Account::Account(int accountId) : id(accountId), balance(0) {}

    int Account::getID() const {
        return id;
    }

    int Account::getBalance() const {
        return balance;
    }

    void Account::deposit(int amount) {
        balance += amount;
    }

    bool Account::withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
