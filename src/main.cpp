#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "include/Bank.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      BANK ACCOUNT SYSTEM" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  1. Create New Account" << std::endl;
    std::cout << "  2. Deposit" << std::endl;
    std::cout << "  3. Withdraw" << std::endl;
    std::cout << "  4. Transfer" << std::endl;
    std::cout << "  5. Check Balance" << std::endl;
    std::cout << "  6. Transaction History" << std::endl;
    std::cout << "  7. List All Accounts" << std::endl;
    std::cout << "  0. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  Choose: ";
}

void createAccount(Bank& bank) {
    std::string name;
    double initial;

    std::cout << "\n--- Create New Account ---" << std::endl;
    std::cout << "Owner name: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "[ERROR] Name cannot be empty." << std::endl;
        return;
    }

    std::cout << "Initial deposit (Rp): ";
    std::cin >> initial;
    clearInput();

    if (initial < 0) {
        std::cout << "[ERROR] Initial deposit cannot be negative." << std::endl;
        return;
    }

    BankAccount* acc = bank.createAccount(name, initial);
    if (acc) {
        std::cout << "\n[SUCCESS] Account created!" << std::endl;
        acc->printInfo();
    } else {
        std::cout << "[ERROR] Failed to create account." << std::endl;
    }
}

void deposit(Bank& bank) {
    std::string id;
    double amount;

    std::cout << "\n--- Deposit ---" << std::endl;
    std::cout << "Account ID: ";
    std::getline(std::cin, id);

    BankAccount* acc = bank.findAccount(id);
    if (!acc) {
        std::cout << "[ERROR] Account not found." << std::endl;
        return;
    }

    std::cout << "Deposit amount (Rp): ";
    std::cin >> amount;
    clearInput();

    if (acc->deposit(amount)) {
        std::cout << "\n[SUCCESS] Deposit successful!" << std::endl;
        acc->printInfo();
    } else {
        std::cout << "[ERROR] Invalid amount." << std::endl;
    }
}

void withdraw(Bank& bank) {
    std::string id;
    double amount;

    std::cout << "\n--- Withdraw ---" << std::endl;
    std::cout << "Account ID: ";
    std::getline(std::cin, id);

    BankAccount* acc = bank.findAccount(id);
    if (!acc) {
        std::cout << "[ERROR] Account not found." << std::endl;
        return;
    }

    std::cout << "Current Balance: Rp " << std::fixed << std::setprecision(2) << acc->getBalance() << std::endl;
    std::cout << "Withdraw amount (Rp): ";
    std::cin >> amount;
    clearInput();

    if (acc->withdraw(amount)) {
        std::cout << "\n[SUCCESS] Withdrawal successful!" << std::endl;
        acc->printInfo();
    } else {
        std::cout << "[ERROR] Insufficient balance or invalid amount." << std::endl;
    }
}

void transfer(Bank& bank) {
    std::string fromId, toId;
    double amount;

    std::cout << "\n--- Transfer ---" << std::endl;
    std::cout << "From Account ID: ";
    std::getline(std::cin, fromId);
    std::cout << "To Account ID: ";
    std::getline(std::cin, toId);

    BankAccount* from = bank.findAccount(fromId);
    BankAccount* to = bank.findAccount(toId);

    if (!from) {
        std::cout << "[ERROR] Sender account not found." << std::endl;
        return;
    }
    if (!to) {
        std::cout << "[ERROR] Receiver account not found." << std::endl;
        return;
    }

    std::cout << "Transfer amount (Rp): ";
    std::cin >> amount;
    clearInput();

    if (bank.transfer(fromId, toId, amount)) {
        std::cout << "\n[SUCCESS] Transfer successful!" << std::endl;
        std::cout << "Sender:" << std::endl;
        from->printInfo();
        std::cout << "Receiver:" << std::endl;
        to->printInfo();
    } else {
        std::cout << "[ERROR] Transfer failed. Check balance or account IDs." << std::endl;
    }
}

void checkBalance(Bank& bank) {
    std::string id;

    std::cout << "\n--- Check Balance ---" << std::endl;
    std::cout << "Account ID: ";
    std::getline(std::cin, id);

    BankAccount* acc = bank.findAccount(id);
    if (!acc) {
        std::cout << "[ERROR] Account not found." << std::endl;
        return;
    }

    acc->printInfo();
}

void transactionHistory(Bank& bank) {
    std::string id;

    std::cout << "\n--- Transaction History ---" << std::endl;
    std::cout << "Account ID: ";
    std::getline(std::cin, id);

    BankAccount* acc = bank.findAccount(id);
    if (!acc) {
        std::cout << "[ERROR] Account not found." << std::endl;
        return;
    }

    acc->printStatement();
}

int main() {
    Bank bank;
    int choice;

    std::cout << "\n========================================" << std::endl;
    std::cout << "   Welcome to Bank Account System" << std::endl;
    std::cout << "========================================\n" << std::endl;

    do {
        showMenu();
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: createAccount(bank); break;
            case 2: deposit(bank); break;
            case 3: withdraw(bank); break;
            case 4: transfer(bank); break;
            case 5: checkBalance(bank); break;
            case 6: transactionHistory(bank); break;
            case 7: bank.listAllAccounts(); break;
            case 0: std::cout << "\nThank you for using Bank Account System. Goodbye!\n" << std::endl; break;
            default: std::cout << "\n[ERROR] Invalid choice." << std::endl; break;
        }
    } while (choice != 0);

    return 0;
}
