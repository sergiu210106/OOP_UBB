#include "BankAccount.h"

void BankAccount::deposit(int amount) {
    balance += amount;
}

bool BankAccount::withdraw(int amount) {
    if (balance < amount) {
        return false;
    }

    balance -= amount;
    return true;
}

long BankAccount::getNumber() const {
    return accountNumber;
}

int BankAccount::getBalance() const {
    return balance;
}