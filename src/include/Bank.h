#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "BankAccount.h"

class Bank {
private:
    std::vector<BankAccount> accounts;
    std::unordered_map<std::string, int> accountIndex;
    int nextAccountId;

    std::string generateAccountId();

public:
    Bank();

    BankAccount* createAccount(const std::string& ownerName, double initialBalance);
    BankAccount* findAccount(const std::string& accountId);
    bool transfer(const std::string& fromId, const std::string& toId, double amount);
    void listAllAccounts() const;
    int getAccountCount() const;
};
