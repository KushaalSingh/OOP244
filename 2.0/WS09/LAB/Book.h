// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "LibraryItem.h"

namespace seneca {

	class Book : public LibraryItem {
	private:
		char* m_author;

	public:
		Book(const char* title, int year, const char* author);
		Book(const Book& src);
		Book& operator 
	};


}

#endif
