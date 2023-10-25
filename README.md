README - Banco 42

Este repositório contém um programa de simulador bancário chamado "Banco 42". O programa é escrito em C++ 98 e permite que os usuários realizem várias operações bancárias, incluindo a criação de contas, encerramento de contas, depósitos, saques, empréstimos e consulta de informações de conta. Aqui está uma breve visão geral do código e suas funcionalidades:

Classes

'Account'

A classe Account representa uma conta bancária com as seguintes funcionalidades:

• Account(int accountId): Construtor que cria uma conta com um ID especificado e saldo inicial zero.
• int getID() const: Método para obter o ID da conta.
• int getBalance() const: Método para obter o saldo da conta.
• void deposit(int amount): Método para depositar um valor na conta.
• bool withdraw(int amount): Método para efetuar um saque da conta.

'Bank'

A classe Bank é o núcleo do simulador bancário e inclui as seguintes funcionalidades:

• int getLiquidity() const: Método para obter a liquidez do banco.
• bool createAccount(int accountId): Método para criar uma nova conta com um ID único.
• bool closeAccount(int accountId): Método para encerrar uma conta existente.
• bool deposit(int accountId, double amount): Método para realizar um depósito em uma conta com uma taxa de 5%.
• bool loan(int accountId, double amount): Método para conceder um empréstimo a uma conta com uma taxa de 5%.
• bool withdraw(int accountId, double amount): Método para efetuar um saque em uma conta.
• void accountInfo(int accountId): Método para exibir informações de uma conta específica.
• static void run(): Método estático que executa o menu principal do banco.

Compilação e Execução

O código está configurado para ser compilado com o comando make. Você pode usar o seguinte conjunto de comandos:

1. 'make' - Compila o código.
2. './ex00' - Executa o programa.

Menu de Opções

O programa oferece um menu de opções que permite aos usuários escolher entre várias operações bancárias, incluindo a criação de contas, depósitos, saques, empréstimos e muito mais.

Estrutura de Arquivos

• main.cpp: Contém a função main que inicia o programa.
• Account.hpp e Account.cpp: Definem a classe Account e suas implementações.
• Bank.hpp e Bank.cpp: Definem a classe Bank e suas implementações.

Observações

O programa possui verificações de erros para garantir que as operações bancárias sejam seguras.
O programa também calcula taxas de 5% em depósitos e empréstimos.
Sinta-se à vontade para experimentar o simulador bancário "Banco 42" e realizar várias operações bancárias. Se tiver alguma dúvida ou sugestão, não hesite em entrar em contato. Divirta-se explorando o código!