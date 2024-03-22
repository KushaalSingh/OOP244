// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "BankAccount.h"

namespace seneca {

	class SavingsAccount : public BankAccount {
	private:
		double m_interest;
		Date m_interestDate;
		void writeInterest(std::ostream& out) const;
		
	public:
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date& dt);
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream & in);
	};

	std::istream& operator>>(std::istream& in, SavingsAccount& acct);
	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);

}

#endif