// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#define NAME_LEN 64
#define MAX_CONTACTS 64

namespace sdds {

	typedef struct {
		char name[NAME_LEN];
		int areacode;
		int prefix;
		int sbscr;
	} dirInfo;

	void phoneDir(const char* programTitle, const char* fileName);

	void importFileData(const char* fileName, dirInfo prsn[]);

	int findContact(const char* input_name, dirInfo prsn[]);

	void displayContactInfo(int index, dirInfo prsn[]);
}

#endif