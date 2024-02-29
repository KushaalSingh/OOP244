#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef ICECREAM_H
#define ICECREAM_H

namespace seneca {

	class Icecream {
	private:
		char* flavour;
		int numberOfScoops;
		double total;
		bool isChoco;
		bool vanillaWafer;
	public:
		void getOrder();
		void printOrder();
		void setOrderToEmpty();
		void assignFlavour();
		void deallocate();
		double returnTotal();
	};

	void displayMenu();
	int getInt(const char* statement, int uprBnd, int lwrBnd);
	bool getvanillaWafer();
	double calculateTotal(int numberOfScoops, bool isChoco, bool vanillaWafer);
	void displayDouble(double num, int _width);
	bool validYesOrNo(const char* str);
}

#endif
