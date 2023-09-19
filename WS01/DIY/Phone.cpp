// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Phone.h"

namespace sdds {
	void phoneDir(const char* programTitle, const char* fileName) {
		char input_name[NAME_LEN];
		int stst = 1;
		struct dirInfo prsn = { "", 0, 0, 0 };

		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << programTitle << " phone direcotry search" << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl;

		while (stst) {
			std::cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << std::endl << "> ";
			std::cin >> input_name;
			if (input_name[0] == '!') {
				stst = 0;
			}
			else {
				importFileData("phones.txt", &prsn);
				// displayAllContacts(&prsn);
				findContact(input_name, &prsn);

			}
		}



	}
	
	void importFileData(const char* fileName, struct dirInfo prsn[]) {
		int i = 0;
		FILE* phns = NULL;
		phns = fopen(fileName, "r");
		if (phns != NULL) {
			while (!feof(phns)) {
				fscanf(phns, "%[^\t]", &prsn[i].name);
				fscanf(phns, "\t%d", &prsn[i].areacode);
				fscanf(phns, "\t%d", &prsn[i].prefix);
				fscanf(phns, "\t%d", &prsn[i].sbscr);
				i++;
			}
			fclose(phns);
		}
	}

	void displayAllContacts(struct dirInfo prsn[]) {
		int i;
		for (i = 0; i < 36; i++) {
			std::cout << prsn[i].name << std::endl;
		}
	}

	void findContact(char* userInput, struct dirInfo prsn[]) {
		int i = 0;
		int j = 0;
		int ct = 0;

		for (i = 0; i < 36; i++) {
			for (j = 0; j < 36; j++) {
				userInput[j] = tolower(userInput[j]);
			}
			for (j = 0; j < 36; j++) {
				prsn[i].name[j] = tolower(prsn[i].name[j]);
			}
		}
		std::cout << userInput << std::endl;
		for (i = 0; i < 36; i++) {
			std::cout << prsn[i].name << std::endl;
		}
	}
}