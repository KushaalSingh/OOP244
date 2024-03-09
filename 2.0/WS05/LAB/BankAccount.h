#define _CRT_SECURE_NO_WARNINGS

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

namespace seneca {

#define MAXLEN_USER 16

#define TRANS_FEE_CHECK 1.25
#define TRANS_FEE_SAVNG 3.50

#define INTR_RATE_CHECK 0.50
#define INTR_RATE_SAVNG 2.50

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
		operator bool() const;
		operator double() const;
		BankAccount& operator++();
		BankAccount& operator--();
		bool operator+=(double value);
		bool operator-=(double value);
		bool operator==(const BankAccount& src) const;
		bool operator<=(double value) const;
		bool operator>(double value) const;
		bool operator<<(BankAccount& src);
		void display() const;
	};

	bool operator>(double lhs, const BankAccount& rhs);
	bool operator<=(double lhs, const BankAccount& rhs);
	
}

#endif