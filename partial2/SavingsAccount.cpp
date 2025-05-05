#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(long number, int bal, double interest) {
    accountNumber = number;
    balance = bal;
    interestRate = interest;
}

void SavingsAccount::saveToFile(std::ofstream& file) {
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    file << "SavingsAccount: ";
    file << "Number: " << accountNumber << ' ';
    file << "Balance: " << balance << ' ';
    file << " Interest Rate: " << interestRate << ' ';
    file << '\n';
}