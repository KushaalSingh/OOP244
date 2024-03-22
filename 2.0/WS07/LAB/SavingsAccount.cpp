// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SavingsAccount.h"
#include "DepositUtility.h"

namespace seneca {

	void SavingsAccount::writeInterest(std::ostream& out) const {
		out.setf(std::ios::fixed);
		out.precision(3);
		out << m_interest << "%";
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) 
		: BankAccount(name, openDate, depInfo, balance) {
		m_interest = interest;
		m_interestDate = interestDate;
	}

	void SavingsAccount::applyInterest(Date& dt) {
		double orgBal = getBalance();
		double intBal = orgBal * m_interest;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		setBalance(orgBal + intBal);
		std::cout << "   ";
		writeCurrency(std::cout, orgBal);
		std::cout << " + ";
		writeCurrency(std::cout, intBal);
		std::cout << " (";
		writeInterest(std::cout);
		std::cout << ") = ";
		writeCurrency(std::cout, getBalance());
		std::cout << " | " << m_interestDate << " => " << dt << std::endl;
		m_interestDate = dt;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const {
		BankAccount::write(std::cout);
		out << " | ";
		writeInterest(std::cout);
		out << " | " << m_interestDate;
		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in) {
		in.ignore();
		BankAccount::read(in);
		std::cout << "Interest Date ";
		in >> m_interestDate;
		std::cout << "Interest Rate: ";
		in >> m_interest;
		return in;
	}

	std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
		return acct.read(in)
	}

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
		return acct.write(out);
	}
}