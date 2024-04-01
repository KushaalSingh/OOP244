// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_LIBRARY_ITEM_H
#define SENECA_LIBRARY_ITEM_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

namespace seneca {

	class LibraryItem {
	private:
		char* m_title;
		int m_year;

	public:
		LibraryItem();
	};


	void allocStringCopy(char*& str, const char* src);
}

#endif 