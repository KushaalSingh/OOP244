#define _CRT_SECURE_NO_WARNINGS

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <cstring>
#include <cstdio>

namespace seneca {

#define MAXLEN_USER 16

#define TRANS_FEE_CHECK 1.25
#define TRANS_FEE_SAVNG 3.30

#define INT_RATE_CHECK 0.50
#define INT_RATE_SAVNG 2.50

	class BankAccount {
	private:
		char m_userName[MAXLEN_USER];
		double m_funds;
		bool m_checking;
		int m_monthlyTransactions;
		bool isOpen() const;
	public:
		BankAccount(const char* name = nullptr, bool checking = false);
		bool setup(const char* name, bool checking);
	};
}

#endif