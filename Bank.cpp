#include "Bank.hpp"

    int Bank::getLiquidity() const {
        return liquidity;
    }

    bool Bank::createAccount(int accountId) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getID() == accountId) {
                std::cout << "Erro: Já existe uma conta com o mesmo ID." << std::endl;
                return false;
            }
        }
        Account newAccount(accountId);
        accounts.push_back(newAccount);
        std::cout << "Conta criada com sucesso! Bem-vindo!" << std::endl;
        return true;
    }

//excluir conta//
    bool Bank::closeAccount(int accountId) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getID() == accountId) {
                accounts.erase(accounts.begin() + i);
                std::cout << "Conta com ID " << accountId << " foi encerrada." << std::endl;
                return true;
            }
        }
        std::cout << "Erro: conta com ID" << accountId << "não encontrada." << std::endl;
        return false;
    }

//realiza deposito//
    bool Bank::deposit(int accountId, double amount) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getID() == accountId) {
                double fee = amount * 0.05;
                liquidity += fee;
                accounts[i].deposit(amount - fee);
                std::cout << "Deposito realizado com sucesso" << std::endl;
                return true;
            }
        }
        std::cout << "Erro: conta com ID " << accountId << " não encontrada." << std::endl;
        return false;
    }
//realizar emprestimo//
    bool Bank::loan(int accountId, double amount) {
        if (liquidity < amount) {
            std::cout << "Valor indisponivel para emprestimo." << std::endl;
            return false;
        } else {
              for (size_t i = 0; i < accounts.size(); ++i) {
                    if (accounts[i].getID() == accountId) {
                        double fee = amount * 0.05;
                        liquidity += fee;
                        accounts[i].deposit(amount - fee);
                        return true;
                    }
                }
            } 
        std::cout << "Erro: conta com ID " << accountId << " não encontrada." << std::endl;
        return false;
    }

// realiza saque//
    bool Bank::withdraw(int accountId, double amount) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getID() == accountId) {
                return accounts[i].withdraw(amount);
                return true;
            }
        }
        std::cout << "Erro: conta com ID " << accountId << " não encontrada." << std::endl;
        return false;
    }

//display conta//
    void Bank::accountInfo(int accountId) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getID() == accountId) {
            std::cout << "Informações da Conta:" << std::endl;
            std::cout << "ID da Conta: " << accounts[i].getID() << std::endl;
            std::cout << "Saldo da Conta: " << accounts[i].getBalance() << std::endl;
            return;
        }
    }
    std::cout << "Erro: conta com ID " << accountId << " não encontrada." << std::endl;
}


//mostra menu e realiza escolhas//
    void Bank::run() { 
        Bank bank;
        char choice;

        while (true) {
            std::cout << " - Menu - Banco 42 " << std::endl;
            std::cout << "1. Criar conta" << std::endl;
            std::cout << "2. Encerrar conta" << std::endl;
            std::cout << "3. Deposito" << std::endl;
            std::cout << "4. Saque" << std::endl;
            std::cout << "5. Emprestimo" << std::endl;
            std::cout << "6. Informacoes do Banco" << std::endl;
            std::cout << "7. Informacoes da Conta" << std::endl;
            std::cout << "Escolha um opção: ";
            std::cin >> choice;

            switch (choice) {
                case '1': {
                    int accountId;
                    std::cout << "Escolha um ID: ";
                    std::cin >> accountId;
                    bank.createAccount(accountId);
                    break;
                }
                case '2': {
                    int accountId;
                    std::cout << "Digite o ID da sua conta:  ";
                    std::cin >> accountId;
                    bank.closeAccount(accountId);
                    break;
                }
                case '3': {
                    int accountId;
                    double amount;
                    std::cout << "Digite o ID da sua conta: ";
                    std::cin >> accountId;
                    std::cout << "Digite o valor para deposito: ";
                    std::cin >> amount;
                    bank.deposit(accountId, amount);
                    break;
                }
                case '4': {
                    int accountId;
                    double amount;
                    std::cout << "Digite o ID da sua conta: ";
                    std::cin >> accountId;
                    std::cout << "Digite o valor para saque: ";
                    std::cin >> amount;
                    if (bank.withdraw(accountId, amount)) {
                        std::cout << "Saque realizado com sucesso!." << std::endl;
                    } else {
                        std::cout << "Erro: Valor indisponivel para saque." << std::endl;
                    }
                    break;
                }
                case '5': {
                    int accountId;
                    double amount;
                    std::cout << "Digite o ID da sua conta: ";
                    std::cin >> accountId;
                    std::cout << "Digite o valor para emprestimo: ";
                    std::cin >> amount;
                    if (bank.loan(accountId, amount)) {
                        std::cout << "Emprestimo realizado com sucesso!." << std::endl;
                    } 
                     break;
                }
                    case '6':
                        std::cout << "Informações do Banco:" << std::endl;
                        std::cout << "Saldo do Banco: " << bank.getLiquidity() << std::endl;
                        break;
                    case '7': {
                        int accountId;
                        std::cout << "Digite o ID da sua conta: ";
                        std::cin >> accountId;
                        bank.accountInfo(accountId);
                    }
                        return;
                    default:
                        std::cout << "Opção inválida! Tente novamente." << std::endl;
                        break;
            }
        }
    }
