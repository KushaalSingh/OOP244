// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Book.h"

namespace seneca {

	Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year), m_author(allocStr(m_author, author)) {}

	Book::Book(const Book& src) : LibraryItem(src.title(), src.year()), m_author(allocStr(m_author, src.m_author)) {}

	Book& Book::operator= (const Book& src) {
		setYear(src.year());
		deallocMemory();
		allocStr(m_author, src.m_author);
		allocStr(titleAdd(), src.title());
		return *this;
	}

	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	std::ostream& Book::display(std::ostream& ostr) const {
		LibraryItem::display() << std::endl << "Author: " << m_author;
		return ostr;
	}

	bool Book::operator> (const Book& src) const {
		if (!m_author || !src.m_author) return false;
		return strcmp(m_author, src.m_author) > 0;
	}

	void Book::deallocMemory() {
		LibraryItem::deallocMemory();
		delete[] m_author;
		m_author = nullptr;
	}
}