#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "iAccount.h"
#include "Account.h"

namespace seneca {

	class SavingsAccount : public Account {
	private:
		double m_interestRate;
		double calculateInterest() const;
		double formattedInterestRate() const;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd() override;
		void display(std::ostream& out = std::cout) const override;
	};

}


#endif
