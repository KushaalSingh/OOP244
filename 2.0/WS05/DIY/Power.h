#ifndef SENECA_POWER_H
#define SENECA_POWER_H

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>

namespace seneca {

#define MAX_NAME_LENGTH 50

	class Power {
	private:
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;
	public:
		Power();
		Power(const char* name, int rarity);
		void setEmpty();
		void createPower(const char* name, int rarity);

		const char* checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};

	void displayDetails(Power* powers, int size);
}
#endif