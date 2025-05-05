#include "BankAccount.h"

class CheckingAccount : public BankAccount {
    private:
        int overdraftLimit;
    
    public:
        CheckingAccount(long number, int bal, int oLimit);
        virtual void saveToFile(std::ofstream & file) override;
        
        bool withdraw(int amount);
        int getLimit() const;

        ~CheckingAccount() = default;
};