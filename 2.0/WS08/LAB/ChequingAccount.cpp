// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "ChequingAccount.h"

namespace seneca {

	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account(balance), m_transactionFee(isValid(transactionFee)), m_monthlyFee(isValid(monthlyFee)) {}

	bool ChequingAccount::credit(double amount) {
		if (Account::credit(amount)) {
			Account::debit(m_transactionFee);
			return true;
		}
		return false;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const {
		out << "Account Type: Chequing" << std::endl;
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << std::endl;
		out << "Per Transaction Fee: " << m_transactionFee << std::endl;
		out << "Monthly Fee: " << m_monthlyFee << std::endl;
	}
}