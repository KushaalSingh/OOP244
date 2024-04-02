// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Book.h"

namespace seneca {

	Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year), m_author(allocStr(m_author, author)) {}

	Book::Book(const Book& src) : LibraryItem(src.title(), src.year()), m_author(allocStr(m_author, src.m_author)) {}

}