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

	std::ostream& BankAccount::write(std::ostream& out) const {
		out << ">> " << m_name << " | ";
		writeCurrency(std::cout, m_balance);
		out << " | " << m_openDate << " | " << m_depInfo << std::endl;
	}

	std::istream& BankAccount::read(std::istream& in) {
		std::cout << "Name: ";
		in.getline(m_name, NAME_LEN);
		std::cout << "Opening Balance: ";
		in >> m_balance;
		std::cout << "Date Opened ";
		m_openDate.read(in);
		m_depInfo.read(in);
		return in;
	}

	std::istream& operator>>(std::istream& in, BankAccount& acct) {
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
		return acct.write(out);
	}
}