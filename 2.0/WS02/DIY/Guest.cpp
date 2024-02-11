#include "Room.h"

namespace seneca {
	void set(Guest& guest, const char* first, const char* last, int age) {
		guest.m_adult = age >= 18 ? true : false;
		if (first != nullptr) {
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
		}
		if (last != nullptr) {
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
		}
	}

	void print(const Guest& guest) {
		if (guest.m_firstName != nullptr && guest.m_lastName != nullptr) {
			std::cout << guest.m_firstName << " " << guest.m_lastName << " ";
			if (!guest.m_adult) std::cout << "(child)" << std::endl;
		}
		else std::cout << "Vacated!" << std::endl;
	}

	void book(Guest& guest) {
		char name[FIRST_NAME], surName[LAST_NAME];
		int age;
		std::cout << "Name: ";
		std::cin.getline(name, FIRST_NAME);
		std::cout << "Lastname: ";
		std::cin.getline(surName, LAST_NAME);
		std::cout << "Age: ";
		std::cin >> age;
	}

	void vacate(Guest& guest) {
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}
}