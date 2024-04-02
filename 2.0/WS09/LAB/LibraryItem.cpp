// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "LibraryItem.h"

namespace seneca {

	LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char* title, int year) : m_title(allocStr(m_title, m_title)), m_year(year) {}

    LibraryItem::LibraryItem(const LibraryItem& src) : m_title(allocStr(m_title, src.m_title)), m_year(src.m_year) {}

    LibraryItem& LibraryItem::operator= (const LibraryItem& src) {
        m_year = src.m_year;
        deallocMemory();
        allocStr(m_title, src.m_title);
    }

    LibraryItem::~LibraryItem() {
        deallocMemory();
    }

    std::ostream& LibraryItem::display(std::ostream& ostr = std::cout) const {
        std::cout << "Title: " << m_title << " (" << m_year << ") ";
        return ostr;
    }

    char* LibraryItem::title() const {
        return m_title;
    }

    int LibraryItem::year() const {
        return m_year;
    }

    void LibraryItem::deallocMemory() {
        delete[] m_title;
        m_title = nullptr;
    }

    char* allocStr(char*& str, const char* src) {
        str = new char[strlen(src) + 1];
        strcpy(str, src);
        return str;
    }
}