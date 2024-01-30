#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile(void);
	bool read(char*& prefix);
	bool read(int& population);
	bool getPostalCode(char* prefix);
	int numberOfRecords(void);
}
#endif