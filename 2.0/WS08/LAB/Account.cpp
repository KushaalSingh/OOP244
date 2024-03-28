#include "Account.h"

namespace seneca {

	Account::Account(double amount) : m_balance(amount < 1.00 ? 0.00 : amount) {}

	bool Account::credit(double amount) {
		if (amount < 1.00) return false;
		else m_balance += amount;
		return true;
	}

	bool Account::debit(double amount) {
		if (amount < 1.00) return false;
		else m_balance -= amount;
		return true;
	}

	double Account::balance() const {
		return m_balance;
	}



}