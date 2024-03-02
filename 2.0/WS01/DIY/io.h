#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca {
	void printInt(int value, int fieldWidth, const char* symbol);
	int intDigits(int value);
	void goBack(int n);
	void labelLine(int n, const char* label);
	void line(int n);
}

#endif 