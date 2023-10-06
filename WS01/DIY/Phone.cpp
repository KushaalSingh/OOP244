// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include "Phone.h"

namespace sdds {
	void phoneDir(const char* programTitle, const char* fileName) {
		char input_name[NAME_LEN];
		int stst = 1;
		dirInfo prsn[MAX_CONTACTS] = { "", 0, 0, 0 };
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << programTitle << " phone direcotry search" << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl;

		while (stst) {
			std::cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << std::endl << "> ";
			std::cin >> input_name;
			if (input_name[0] == '!') {
				std::cout << "Thank you for using Star Wars directory." << std::endl;
				stst = 0;
			}
			else {
				importFileData("phones.txt", prsn);
				int index = findContact(input_name, prsn);
				displayContactInfo(index, prsn);
			}
		}
	}

	void importFileData(const char* fileName, dirInfo prsn[]) {
		int i = 0;
		FILE* phns = NULL;
		phns = fopen(fileName, "r");
		if (phns != NULL) {
			while (!feof(phns)) {
				fscanf(phns, "%[^\t]", prsn[i].name);
				fscanf(phns, "\t%d", &prsn[i].areacode);
				fscanf(phns, "\t%d", &prsn[i].prefix);
				fscanf(phns, "\t%d", &prsn[i].sbscr);
				i++;
			}
			fclose(phns);
		}
	}

	int findContact(const char* userInput, dirInfo prsn[]) {
		int i, j;
		int foundIndex = -1;

		char lowerCaseInput[NAME_LEN];
		strcpy(lowerCaseInput, userInput);
		for (i = 0; i < MAX_CONTACTS; i++) lowerCaseInput[i] = tolower(lowerCaseInput[i]);

		for (i = 0; i < MAX_CONTACTS; i++) {
			char lowerCaseContact[NAME_LEN];
			strcpy(lowerCaseContact, prsn[i].name);
			for (j = 0; j < NAME_LEN; j++) lowerCaseContact[j] = tolower(lowerCaseContact[j]);
			
			const char* ifFound = strstr(lowerCaseContact, lowerCaseInput);
			if (ifFound != nullptr) {
				foundIndex = i;
				return foundIndex;
			}
		}
		return foundIndex;
	}

	void displayContactInfo(int index, dirInfo prsn[]) {
		if (index != -1) {
			std::cout << prsn[index].name << ": " << "(" << prsn[index].areacode << ") "
				<< prsn[index].prefix << "-" << prsn[index].sbscr << std::endl;
		}
		else {
			return;
		}
	}
}