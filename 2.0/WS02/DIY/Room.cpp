#include "Room.h"

namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		room.m_guests = new Guest[numberOfGuests];
		strcpy(room.m_roomNumber, roomNumber);
	}

	void print(const Room& room) {
		int i;
		std::cout << "Room Number" << ": " << room.m_roomNumber << std::endl;
		for (i = 0; i < room.m_noOfGuests; i++) {
			std::cout << "    ";
			print(room.m_guests[i]);
		}
	}

	void book(Room& room) {
		int i;
		std::cout << "Room number: ";
		std::cin.getline(room.m_roomNumber, 6);
		std::cout << "Number of guests: ";
		std::cin >> room.m_noOfGuests;
		room.m_guests = new Guest[room.m_noOfGuests];
		for (i = 0; i < room.m_noOfGuests; i++) {
			std::cout << i << ":" << std::endl;
			book(room.m_guests[i]);
		}
	}

	void vacate(Room& room) {
		int i;
		delete[] room.m_guests;
		for (i = 0; i < room.m_noOfGuests; i++) {
			vacate(room.m_guests[i]);
		}
	}





}