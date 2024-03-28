#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "iAccount.h"
#include "Account.h"

namespace seneca {

	class SavingsAccount : public Account {
	private:
		double m_interestRate;

	public:
		SavingsAccount(double balance, double interestRate);
	};

}


#endif
