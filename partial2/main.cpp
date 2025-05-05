#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <cassert>

using namespace std;

BankAccount* loadFromFile(std::ifstream& file) {
    if (!file.is_open()) {
        return nullptr;
    }

    string typeOfAccount;
    file >> typeOfAccount;  // Read account type (e.g., "SavingsAccount:")

    cout << "Account Type: '" << typeOfAccount << "'" << endl;  // Debugging output

    // Check if it's a "SavingsAccount"
    if (typeOfAccount == "SavingsAccount:") {
        long number;
        int bal;
        double interest;

        // Parse the account number, balance, and interest rate
        file >> typeOfAccount >> number;  // Read "Number:" and the number
        file >> typeOfAccount >> bal;     // Read "Balance:" and the balance
        file >> typeOfAccount >> interest; // Read "Interest Rate:" and the interest rate

        return new SavingsAccount{number, bal, interest};
    } 
    // Check if it's a "CheckingAccount"
    else if (typeOfAccount == "CheckingAccount:") {
        long number;
        int bal, oLimit;

        // Parse the account number, balance, and overdraft limit
        file >> typeOfAccount >> number;  // Read "Number:" and the number
        file >> typeOfAccount >> bal;     // Read "Balance:" and the balance
        file >> typeOfAccount >> oLimit;  // Read "Overdraft Limit:" and the overdraft limit

        return new CheckingAccount{number, bal, oLimit};
    } 
    else {
        return nullptr;  // Invalid account type
    }
}


int main() {
    CheckingAccount ca{1, 20, 10};

    assert(ca.withdraw(40) == false);
    assert(ca.withdraw(30) == true);
    assert(ca.getBalance() == -10);
    ca.deposit(1000);
    assert(ca.getBalance() == 990);
    assert(ca.withdraw(1001) == false);

    SavingsAccount sa {2, 100, 30};

    ofstream outFile{"my_file.txt", ios::trunc};

    if (!outFile) {
        cerr << "Failed to open file for reading!\n";

        return -1;
    }

    ca.saveToFile(outFile);
    sa.saveToFile(outFile);
    ifstream inFile{"my_file.txt"};

    BankAccount* accountFromFile = loadFromFile(inFile);
    
    if (accountFromFile) {
        SavingsAccount* loadedSA = dynamic_cast<SavingsAccount*>(accountFromFile);
        if (loadedSA) {
            cout << "Loaded SavingsAccount with number " << loadedSA->getNumber() << endl;
        } else {
            CheckingAccount* loadedCA = dynamic_cast<CheckingAccount*>(accountFromFile);
            if (loadedCA) {
                cout << "Loaded CheckingAccount with number " << loadedCA->getNumber() << endl;
            }
        }
        delete accountFromFile; 
    } else {
        cout << "Failed to load account from file" << endl;
    }

    

    return 0;
}