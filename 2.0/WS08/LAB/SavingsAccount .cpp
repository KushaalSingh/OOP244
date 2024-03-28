#include "SavingsAccount.h"

namespace seneca {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), m_interestRate(interestRate < 1.00 ? 0.00 : interestRate) {}

	void SavingsAccount::monthEnd() {
		credit(calculateInterest());
	}

	double SavingsAccount::calculateInterest() const {
		return m_interestRate * balance();
	}

}