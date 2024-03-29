// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CHEQUING_ACCOUNT_H
#define SENECA_CHEQUING_ACCOUNT_H

#include "iAccount.h"
#include "Account.h"

namespace seneca {

	class ChequingAccount : public Account {
	private:
		double m_transactionFee;
		double m_monthlyFee;

	public:
		ChequingAccount(double balance, double transactionFee, double monthlyFee);
		bool credit(double amount) override;
		void monthEnd() override;
		void display(std::ostream& out = std::cout) const override;
	};

}


#endif
