#include "include/BankAccount.h"
#include <iostream>
#include <iomanip>
#include <ctime>

BankAccount::BankAccount(const std::string& id, const std::string& name, double initialBalance)
    : accountId(id), ownerName(name), balance(initialBalance) {
    if (initialBalance > 0) {
        transactions.emplace_back(TransactionType::DEPOSIT, initialBalance, balance, "Initial deposit");
    }
}

std::string BankAccount::getAccountId() const { return accountId; }
std::string BankAccount::getOwnerName() const { return ownerName; }
double BankAccount::getBalance() const { return balance; }

bool BankAccount::deposit(double amount) {
    if (amount <= 0) return false;
    balance += amount;
    transactions.emplace_back(TransactionType::DEPOSIT, amount, balance, "Deposit");
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    transactions.emplace_back(TransactionType::WITHDRAWAL, amount, balance, "Withdrawal");
    return true;
}

void BankAccount::addTransferIn(double amount, const std::string& fromAccount) {
    balance += amount;
    transactions.emplace_back(TransactionType::TRANSFER_IN, amount, balance,
        "Transfer from " + fromAccount);
}

void BankAccount::addTransferOut(double amount, const std::string& toAccount) {
    balance -= amount;
    transactions.emplace_back(TransactionType::TRANSFER_OUT, amount, balance,
        "Transfer to " + toAccount);
}

void BankAccount::printStatement() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  TRANSACTION HISTORY - " << accountId << std::endl;
    std::cout << "  Owner: " << ownerName << std::endl;
    std::cout << "========================================" << std::endl;

    if (transactions.empty()) {
        std::cout << "  No transactions found." << std::endl;
    } else {
        std::cout << std::left << std::setw(5) << "No."
                  << std::setw(15) << "Type"
                  << std::setw(12) << "Amount"
                  << std::setw(14) << "Balance"
                  << "Description" << std::endl;
        std::cout << std::string(60, '-') << std::endl;

        int num = 1;
        for (const auto& t : transactions) {
            std::time_t t_time = t.timestamp;
            char timeStr[26];
            ctime_s(timeStr, sizeof(timeStr), &t_time);
            std::string timeString(timeStr);
            timeString.pop_back();

            std::cout << std::left << std::setw(5) << num++
                      << std::setw(15) << t.getTypeString()
                      << std::setw(12) << std::fixed << std::setprecision(2) << t.amount
                      << std::setw(14) << std::fixed << std::setprecision(2) << t.balanceAfter
                      << t.description << std::endl;
        }
    }

    std::cout << "\n  Current Balance: Rp " << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void BankAccount::printInfo() const {
    std::cout << "  " << accountId << " | " << ownerName
              << " | Balance: Rp " << std::fixed << std::setprecision(2) << balance << std::endl;
}
