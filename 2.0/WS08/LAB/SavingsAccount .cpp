#include "SavingsAccount.h"

namespace seneca {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), m_interestRate(interestRate < 1.00 ? 0.00 : interestRate) {}

	void SavingsAccount::monthEnd() {
		credit(calculateInterest());
	}

	void SavingsAccount::display(std::ostream& out) const {
		out << "Account Type: Savings";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << std::endl;
		out << "Interest Rate (%): " << m_interestRate << std::endl;
	}

	double SavingsAccount::calculateInterest() const {
		return m_interestRate * balance();
	}

}