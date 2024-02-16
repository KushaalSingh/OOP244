#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef GUEST_H
#define GUEST_H

namespace wrk {

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
	void vacate(Guest& guest);
	void nullifyName(Guest& guest);
	bool validateName(const char* fn, const char* ln);
	bool alreadyVacant(Guest& guest);

}

#endif