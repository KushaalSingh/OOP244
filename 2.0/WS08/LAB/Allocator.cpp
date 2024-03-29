// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace seneca {

	// account rates and charges
	//
	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	// calls the appropriate constructor
	//
	iAccount* CreateAccount(const char* str, double balance) {
		iAccount* account = nullptr;
		switch (str[0]) {
		case 'S':
			account = new SavingsAccount(balance, interestRate);
			break;
		case 'C':
			account = new ChequingAccount(balance, transactionFee, monthlyFee);
			break;
		}
		return account;
	}