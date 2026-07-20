#include "include/Bank.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Bank::Bank() : nextAccountId(1) {}

std::string Bank::generateAccountId() {
    std::ostringstream oss;
    oss << "ACC-" << std::setfill('0') << std::setw(4) << nextAccountId++;
    return oss.str();
}

BankAccount* Bank::createAccount(const std::string& ownerName, double initialBalance) {
    if (initialBalance < 0) return nullptr;

    std::string id = generateAccountId();
    accounts.emplace_back(id, ownerName, initialBalance);
    accountIndex[id] = static_cast<int>(accounts.size()) - 1;
    return &accounts.back();
}

BankAccount* Bank::findAccount(const std::string& accountId) {
    auto it = accountIndex.find(accountId);
    if (it != accountIndex.end()) {
        return &accounts[it->second];
    }
    return nullptr;
}

bool Bank::transfer(const std::string& fromId, const std::string& toId, double amount) {
    if (amount <= 0) return false;
    if (fromId == toId) return false;

    BankAccount* from = findAccount(fromId);
    BankAccount* to = findAccount(toId);

    if (!from || !to) return false;
    if (from->getBalance() < amount) return false;

    from->addTransferOut(amount, toId);
    to->addTransferIn(amount, fromId);
    return true;
}

void Bank::listAllAccounts() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          ALL ACCOUNTS" << std::endl;
    std::cout << "========================================" << std::endl;

    if (accounts.empty()) {
        std::cout << "  No accounts found." << std::endl;
    } else {
        for (const auto& acc : accounts) {
            acc.printInfo();
        }
    }

    std::cout << "\n  Total Accounts: " << accounts.size() << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int Bank::getAccountCount() const {
    return static_cast<int>(accounts.size());
}
