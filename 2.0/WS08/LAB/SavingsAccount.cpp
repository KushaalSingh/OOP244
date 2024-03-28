#include "SavingsAccount.h"

namespace seneca {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), m_interestRate(interestRate <= 0.00 ? 0.00 : interestRate) {}

	void SavingsAccount::monthEnd() {
		credit(calculateInterest());
	}

	void SavingsAccount::display(std::ostream& out) const {
		out << "Account Type: Savings" << std::endl;
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << std::endl;
		out << "Interest Rate (%): " << formattedInterestRate() << std::endl;
	}

	double SavingsAccount::calculateInterest() const {
		return m_interestRate * balance();
	}

	double SavingsAccount::formattedInterestRate() const {
		return m_interestRate * 100;
	}

}