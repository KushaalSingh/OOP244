#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#define NUM_CONTACTS 36
#define NAME_LEN 64

namespace sdds {

	typedef struct {
		char name[NAME_LEN];
		int areacode;
		int prefix;
		int sbscr;
	} dirInfo;

	void phoneDir(const char* programTitle, const char* fileName);

	bool takeUserInput(dirInfo prsn[]);

	void displayMatches(const char* userInput, dirInfo prsn[]);

	void display(dirInfo prsn[], int index);

	bool readToStruct(char name[], int& areaCode, int& prefix, int& sbscr);

	void importFileData(dirInfo prsn[]);

	bool openFile(const char* fileName);

	void closeFile(void);

}

#endif