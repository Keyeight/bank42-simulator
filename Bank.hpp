#include "Account.hpp"

class Bank {

private:
    int liquidity;
    std::vector<Account> accounts;

public:
//criacao de contas//

    int getLiquidity() const;

    bool createAccount(int accountId);

//excluir conta//
    bool closeAccount(int accountId);

//realiza deposito//
    bool deposit(int accountId, double amount);
// realiza saque
    bool withdraw(int accountId, double amount);

//menu
    static void run();

//emprestimo
    bool loan(int accountId, double amount);

//display conta
    void accountInfo(int accountId);
};