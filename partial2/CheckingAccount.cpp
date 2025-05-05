#include "CheckingAccount.h"
CheckingAccount::CheckingAccount(long number, int bal, int oLimit) {
    accountNumber = number;
    balance = bal;
    overdraftLimit = oLimit;
}   

void CheckingAccount::saveToFile(std::ofstream& file) {
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    file << "Checking Account: ";
    file << "Number: " << accountNumber << ' ';
    file << "Balance: " << balance << ' ';
    file << "Overdraft Limit: " << overdraftLimit;
    file << '\n';
}

bool CheckingAccount::withdraw(int amount) {
    if (balance + overdraftLimit < amount) {
        return false;
    }

    balance -= amount;
    return true;
}

int CheckingAccount::getLimit() const {
    return overdraftLimit;
}
