#ifndef SDDS_WORD_H 
#define SDDS_WORD_H
namespace sdds {
	#include <cstdio>
	#include <iostream>
	#include <iomanip>
	#include "cStrTools.h"
	using namespace std;

	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;
	const int SORT_BY_OCCURANCE = 1;
	const int SORT_ALPHABETICALLY = 0;

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word words[], int num, const char word[]);
	void addWord(Word words[], int* index, const char newWord[]);
	int readWord(char* word, FILE* fptr, int maxLen);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, int gotoNextLine, int len);
	

}
#endif