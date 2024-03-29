// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Account.h"

namespace seneca {

	Account::Account(double amount) : m_balance(isValid(amount)) {}

	bool Account::credit(double amount) {
		if (amount <= 0.00) return false;
		else m_balance += amount;
		return true;
	}

	bool Account::debit(double amount) {
		if (amount <= 0.00) return false;
		else m_balance -= amount;
		return true;
	}

	double Account::balance() const {
		return m_balance;
	}

	double Account::isValid(double value) const {
		return value <= 0.00 ? 0.00 : value;
	}
}