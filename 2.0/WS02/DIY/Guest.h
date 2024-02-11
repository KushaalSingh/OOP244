#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

namespace seneca {

	const int FIRST_NAME = 32;
	const int LAST_NAME = 64;

	typedef struct {
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	} Guest;

	void set(Guest& guest, const char* first, const char* last, int age);
	void print(const Guest& guest);
	void book(Guest& guest);
	void vacate(Guest& guest)

}

#endif