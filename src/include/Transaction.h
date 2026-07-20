#pragma once

#include <string>
#include <ctime>

enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER_IN,
    TRANSFER_OUT
};

struct Transaction {
    TransactionType type;
    double amount;
    double balanceAfter;
    std::string description;
    std::time_t timestamp;

    Transaction(TransactionType type, double amount, double balanceAfter, const std::string& desc)
        : type(type), amount(amount), balanceAfter(balanceAfter), description(desc), timestamp(std::time(nullptr)) {}

    std::string getTypeString() const {
        switch (type) {
            case TransactionType::DEPOSIT:      return "DEPOSIT";
            case TransactionType::WITHDRAWAL:   return "WITHDRAWAL";
            case TransactionType::TRANSFER_IN:  return "TRANSFER IN";
            case TransactionType::TRANSFER_OUT: return "TRANSFER OUT";
        }
        return "UNKNOWN";
    }
};
