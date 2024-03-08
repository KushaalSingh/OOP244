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

	BankAccount::operator bool() const {
		if (isOpen()) return true;
		else return false;
	}

	BankAccount::operator double() const {
		return m_funds;
	}

	BankAccount& BankAccount::operator++() {
		if (m_funds > 0 && isOpen()) m_funds += m_checking ? (INTR_RATE_CHECK * m_funds) : (INTR_RATE_SAVNG * m_funds);
		return *this;
	}

	BankAccount& BankAccount::operator--() {
		if (isOpen()) m_funds -= m_checking ? (TRANS_FEE_CHECK * m_monthlyTransactions) : (TRANS_FEE_SAVNG * m_monthlyTransactions);
		return *this;
	}

	bool BankAccount::operator+=(double value) {
		if (isOpen()) {
			m_funds += value;
			++m_monthlyTransactions;
			return true;
		}
		return false;
	}

	bool BankAccount::operator-=(double value) {
		if (isOpen()) return *this += value * -1;
		return false;
	}

	bool BankAccount::operator==(const BankAccount& src) const {
		return !strcmp(src.m_userName, m_userName) && src.m_checking == m_checking && std::abs(src.m_funds - m_funds) < 0.001;
	}

	bool BankAccount::operator>(double value) const {
		if (isOpen()) return m_funds > value;
		return false;
	}

	bool BankAccount::operator<=(double value) const {
		if (isOpen()) return !*this > value;
		return false;
	}

	bool BankAccount::operator<<(BankAccount& src) { // Comeback to this function and solve the modifiable value issue
		if (src.isOpen() && isOpen() && src.m_funds > 0) {
			bool transfer_1 = src -= src.m_funds;
			bool transfer_2 = *this += src.m_funds;
			if (transfer_1 && transfer_2) {
				std::cout << "Transfer $" << src.m_funds << " from " << src.m_userName << " to " << m_userName << std::endl;
				return true;
			}
		}
		return false;
	}

	void BankAccount::display() const {
		if (isOpen()) {

		}
	}

}