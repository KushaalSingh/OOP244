// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_I_ACCOUNT_H
#define SENECA_I_ACCOUNT_H

#include <iostream>

namespace seneca {

	class iAccount {
	public:
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);


}

#endif
