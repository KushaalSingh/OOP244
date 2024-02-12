#include "Room.h"

namespace seneca {

	/*void set(Guest& guest, const char* first, const char* last, int age) {
		guest.m_adult = (age >= 18);
		if (validateName(first, last)) {
			guest.m_firstName = new char[strlen(first) + 1];
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_firstName, first);
			strcpy(guest.m_lastName, last);
		}
		else nullifyName(guest);
	}*/

	void set(Guest& guest, const char* first, const char* last, int age) {
		guest.m_adult = (age >= 18);
		if (validateName(first, last)) {
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
		}
		if (guest.m_firstName != nullptr && guest.m_lastName != nullptr && !validateName(first, last)) {
			nullifyName(guest);
		}
	}

	void print(const Guest& guest) {
		if (validateName(guest.m_firstName, guest.m_lastName)) {
			std::cout << guest.m_firstName << " " << guest.m_lastName << " ";
			if (!guest.m_adult) std::cout << "(Child)" << std::endl;
			else std::cout << std::endl;
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
		set(guest, name, surName, age);
	}

	void vacate(Guest& guest) {
		if (guest.m_firstName != nullptr) delete[] guest.m_firstName;
		if (guest.m_lastName != nullptr) delete[] guest.m_lastName;
		nullifyName(guest);
	}

	void nullifyName(Guest& guest) {
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}

	bool validateName(const char* fn, const char* ln) {
		return (fn != nullptr) && (fn != "") && (ln != nullptr) && (ln != "");	
	}

	bool alreadyVacant(Guest& guest) {
		return guest.m_firstName == nullptr || !guest.m_firstName || 
			guest.m_lastName == nullptr || !guest.m_lastName;
	}
}