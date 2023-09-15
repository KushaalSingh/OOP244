#include <iostream>
#include "Word.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}