#pragma once
#include <fstream>
using std::ofstream

class BankAccount {
	private:
		std::string m_name;
		std::string m_number;
		double m_balance;
	public:
		BankAccount();
		BankAccount(const std::string name, const std::string m_number, const double m_balance);
		bool withdraw(const double amount);
		void deposit(const double amount);
		friend std::ostream& operator<<(std::ostream& os, const BankAccount& bank);
		
		double get_balance() const;
		std::string get_name() const;
		std::string get_number() const;
};	
