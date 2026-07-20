#pragma once

#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
private:
    std::string accountId;
    std::string ownerName;
    double balance;
    std::vector<Transaction> transactions;

public:
    BankAccount(const std::string& id, const std::string& name, double initialBalance);

    std::string getAccountId() const;
    std::string getOwnerName() const;
    double getBalance() const;

    bool deposit(double amount);
    bool withdraw(double amount);
    void addTransferIn(double amount, const std::string& fromAccount);
    void addTransferOut(double amount, const std::string& toAccount);

    void printStatement() const;
    void printInfo() const;
};
