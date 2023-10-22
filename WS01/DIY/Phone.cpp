#include "Phone.h"

namespace sdds {
	FILE* fptr;

	void phoneDir(const char* programTitle, const char* fileName) {
		dirInfo prsn[NUM_CONTACTS];
		auto fileOpened = openFile("phones.txt");
		if (!fileOpened) std::cout << "ERROR: Couldn't open the file." << std::endl;
		importFileData(prsn);
		closeFile();

		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << programTitle << " phone direcotry search" << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl;

		while (takeUserInput(prsn));

		std::cout << "Thank you for using Star Wars directory." << std::endl;
	}

	bool takeUserInput(dirInfo prsn[]) {
		char userInput[NAME_LEN];
		std::cout << "Enter a partial name to search(no spaces) or enter '!' to exit" << std::endl << "> ";
		std::cin >> userInput;
		if (userInput[0] == '!') return false;
		displayMatches(userInput, prsn);
		return true;
	}

	void displayMatches(const char* userInput, dirInfo prsn[]) {
		int i, k;
		char tempName[NAME_LEN];
		char tempUserInput[NAME_LEN];
		strcpy(tempUserInput, userInput);

		for (i = 0; i < NUM_CONTACTS; i++) {
			strcpy(tempName, prsn[i].name);
			for (k = 0; k < tempName[k] != '\0'; k++) tempName[k] = tolower(tempName[k]);
			for (k = 0; k < tempUserInput[k] != '\0'; k++) tempUserInput[k] = tolower(tempUserInput[k]);
			const char* result = strstr(tempName, tempUserInput);
			if (result != nullptr) display(prsn, i);
		}
	}

	void display(dirInfo prsn[], int index) {
		std::cout << prsn[index].name << ": (" << prsn[index].areacode << ") " << prsn[index].prefix << "-"
			<< prsn[index].sbscr << std::endl;
	}

	bool readToStruct(char name[], int& areaCode, int& prefix, int& sbscr) {
		while (!feof(fptr) && (fscanf(fptr, "%[^\t]\t%d\t%d\t%d\n", name, &areaCode, &prefix, &sbscr)) == 4) return true;
		return false;
	}

	void importFileData(dirInfo prsn[]) {
		int i;
		for (i = 0; i < NUM_CONTACTS; i++) {
			readToStruct(prsn[i].name, prsn[i].areacode, prsn[i].prefix, prsn[i].sbscr);
		}
	}

	bool openFile(const char* fileName) {
		fptr = fopen(fileName, "r");
		return fptr != NULL;
	}

	void closeFile(void) {
		if (fptr) fclose(fptr);
	}
}