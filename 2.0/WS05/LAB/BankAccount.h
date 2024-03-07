#define _CRT_SECURE_NO_WARNINGS

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <cstring>
#include <cstdio>

#define MAXLEN_USER 16

namespace seneca {

	class BankAccount {
	private:
		char m_username[MAXLEN_USER];
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