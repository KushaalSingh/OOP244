// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "iAccount.h"

namespace seneca {

	class Account : public iAccount {
	private:
		double m_balance;

	public:
		Account(double amount = 0.00);
		bool credit(double amount) override;
		bool debit(double amount) override;
		
	protected:
		double balance() const;
		double isValid(double value) const;
	};
}

#endif
