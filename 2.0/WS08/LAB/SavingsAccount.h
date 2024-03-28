#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "iAccount.h"
#include "Account.h"

namespace seneca {

	class SavingsAccount : public Account {
	private:
		double m_interestRate;
		double calculateInterest() const;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd() override;
	};

}


#endif
