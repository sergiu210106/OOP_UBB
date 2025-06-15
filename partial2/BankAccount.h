#pragma once
#include <fstream>
#include <iostream>

class BankAccount {
    protected:
        long accountNumber;
        int balance;
    public:
        long getNumber() const;
        int getBalance() const;

        void deposit(int amount);
        bool withdraw(int amount);

        virtual ~BankAccount() = default;

        virtual void saveToFile(std::ofstream& file) = 0;
};
