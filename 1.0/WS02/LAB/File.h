#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();

	bool read(char*& name);

	bool read(int& empNum);

	bool read(double& empSal);

}

#endif