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
		LibraryItem(const char* title, int year);
		LibraryItem(const LibraryItem& src);
		LibraryItem& operator= (const LibraryItem& src);
		virtual ~LibraryItem();
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;

	protected:
		char* title() const;
		int year() const;
		virtual void deallocMemory();
		void setYear(int year);
		char*& titleAdd();
	};

	char* allocStr(char*& str, const char* src);
}

#endif 