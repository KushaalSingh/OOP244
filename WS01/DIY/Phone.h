// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds {
	const int NAME_LEN = 32;

	struct dirInfo {
		char name[NAME_LEN];
		int areacode;
		int prefix;
		int sbscr;
	};

	void phoneDir(const char* programTitle, const char* fileName);

	void importFileData(const char* fileName, struct dirInfo prsn[]);

	void displayAllContacts(struct dirInfo prsn[]);

	void findContact(char* userInput, struct dirInfo prsn[]);
}

#endif