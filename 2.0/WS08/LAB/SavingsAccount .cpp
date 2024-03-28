#include "SavingsAccount.h"

namespace seneca {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), m_interestRate(interestRate < 1.00 ? 0 : interestRate) {}

}