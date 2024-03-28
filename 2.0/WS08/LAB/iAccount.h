#ifndef SENECA_I_ACCOUNT_H
#define SENECA_I_ACCOUNT_H

#include <iostream>

namespace seneca {

	class iAccount {
	public:
		virtual bool credit(double value) = 0;
		virtual bool debit(double value) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);


}

#endif
