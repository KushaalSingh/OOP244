// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "BankAccount.h"

namespace seneca {

	double BankAccount::getBalance() const {
		return m_balance;
	}

	void BankAccount::setBalance(double balance) {
		m_balance = balance;
	}

	void BankAccount::writeCurrency(std::ostream& out, double amount) const {
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "$" << amount;
	}

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) {
		strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;
	}

	std::ostream& BankAccount::write(std::ostream & out) {

	}
}