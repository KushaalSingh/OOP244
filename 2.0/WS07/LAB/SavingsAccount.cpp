// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SavingsAccount.h"
#include "DepositUtility.h"

namespace seneca {

	void SavingsAccount::writeInterest(std::ostream& out) const {
		out.setf(std::ios::fixed);
		out.precision(3);
		out << m_interest << "%";
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance) {
		m_interest = interest;
		m_interestDate = interestDate;
	}

	void SavingsAccount::applyInterest(Date& dt) {
		double orgBal = getBalance();
		double intBal = orgBal * m_interest;
		setBalance(orgBal + intBal);
		std::cout << "   " << orgBal << " + " << intBal << " (";
		writeInterest(std::cout);
		std::cout << ") = ";
		writeCurrency(std::cout, getBalance());
		std::cout << " | " << m_interestDate << " => " << dt;
		m_interestDate = dt;
	}

	std::ostream& write(std::ostream& out) {

	}

}