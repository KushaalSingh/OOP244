#include "Account.h"

namespace seneca {

	Account::Account(double amount) {
		if (amount < 1.00) m_balance = 0.00;
		else m_balance = amount;
	}


}