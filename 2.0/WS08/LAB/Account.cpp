#include "Account.h"

namespace seneca {

	Account::Account(double amount) {
		if (amount < 1.00) m_balance = 0.00;
		else m_balance = amount;
	}

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