#include "BankAccount.h"

class SavingsAccount : public BankAccount{
    private:
        double interestRate;
    
    public:
        SavingsAccount(long number, int bal, double interest);

        virtual void saveToFile(std::ofstream& file) override;

        ~SavingsAccount() = default;
};