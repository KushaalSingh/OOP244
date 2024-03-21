// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_BANK_ACCOUNT_H
#define SENECA_BANK_ACCOUNT_H

#include "DepositUtility.h"

#define NAME_LEN 50

namespace seneca {

	class BankAccount {
	private:
		char m_name[NAME_LEN];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance;

	protected:
		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(std::ostream& out, double amount) const;

	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		std::ostream& write(std::ostream& out = std::cout) const;
		std::istream& read(std::istream& in);
	};

	std::istream& operator>>(std::istream& in, BankAccount& acct);
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}


#endif