#include "BankAccount.h"

namespace seneca {

	BankAccount::BankAccount(const char* name, bool checking) {
		m_userName[0] = '\0';
		setup(name, checking);
	}

	bool BankAccount::setup(const char* name, bool checking) {
		if (isOpen()) return false;
		if (name == nullptr) return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	bool BankAccount::isOpen() const {
		return m_userName[0] != '\0';
	}


}