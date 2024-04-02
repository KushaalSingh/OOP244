// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "LibraryItem.h"

namespace seneca {

	class Book : public LibraryItem {
	private:
		char* m_author;
		void deallocMemory() override;

	public:
		Book(const char* title, int year, const char* author);
		Book(const Book& src);
		~Book();
		Book& operator= (const Book& src);
		std::ostream& display(std::ostream& ostr = std::cout) const override;
		bool operator> (const Book& src) const;
	};
}

#endif
