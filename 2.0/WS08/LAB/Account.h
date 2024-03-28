#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "iAccount.h"

namespace seneca {

	class Account : public iAccount {
	private:
		double m_balance;

	public:
		Account(double amount = 0.00);

		
	};


}

#endif
