#include <iostream>
#include <vector>

class Account {

private:
    int id;
    int balance;

public:
    Account(int accountId);

    int getID() const;

    int getBalance() const;

    void deposit(int amount);

    bool withdraw(int amount);
};