// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "LibraryItem.h"

namespace seneca {

	LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}














    void allocStringCopy(char*& str, const char* src) {
        delete[] str;
        str = new char[strlen(src) + 1];
        strcpy(str, src);
    }

}