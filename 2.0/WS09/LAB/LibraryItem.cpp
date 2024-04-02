// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "LibraryItem.h"

namespace seneca {

	LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char* title, int year) : m_year(year) {
        m_title = new char(strlen(title) + 1);
        strcpy(m_title, title);
    }

    LibraryItem::LibraryItem(const LibraryItem& src) : m_year(src.m_year) {
        m_title = new char(strlen(src.m_title) + 1);
        strcpy(m_title, src.m_title);
    }

    LibraryItem& LibraryItem::operator= (const LibraryItem& src) {
        deallocMemory();
        m_year = src.m_year;
        m_title = new char(strlen(src.m_title) + 1);
        strcpy(m_title, src.m_title);
    }

    LibraryItem::~LibraryItem() {
        deallocMemory();
    }

    std::ostream& LibraryItem::display(std::ostream& ostr = std::cout) const {
        std::cout << "Title: " << m_title << " (" << m_year << ") ";
        return ostr;
    }


    void LibraryItem::deallocMemory() {
        delete[] m_title;
        m_title = nullptr;
    }

}