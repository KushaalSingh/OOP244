#include "Room.h"

namespace wrk {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		int i;
		room.m_guests = new Guest[numberOfGuests];
		for (i = 0; i < numberOfGuests; i++) nullifyName(room.m_guests[i]);
		room.m_noOfGuests = numberOfGuests;
		strcpy(room.m_roomNumber, roomNumber);
	}

	void print(const Room& room) {
		int i;
		if (room.m_noOfGuests == 0) std::cout << "Empty Room!" << std::endl;
		else {
			std::cout << "Room Number" << ": " << room.m_roomNumber << std::endl;
			for (i = 0; i < room.m_noOfGuests; i++) {
				std::cout << "    ";
				print(room.m_guests[i]);
			}
		}
	}

	void book(Room& room) {
		int i, guestCount;
		char roomNum[6];
		std::cout << "Room number: ";
		std::cin.ignore();
		std::cin.getline(roomNum, 6);
		std::cout << "Number of guests: ";
		std::cin >> guestCount;
		std::cin.ignore();
		set(room, guestCount, roomNum);
		for (i = 0; i < room.m_noOfGuests; i++) {
			std::cout << i + 1 << ":" << std::endl;
			book(room.m_guests[i]);
			std::cin.ignore();
		}
	}

	void vacate(Room& room) {
		int i;
		for (i = 0; i < room.m_noOfGuests; i++) {
			vacate(room.m_guests[i]);
		}
		room.m_noOfGuests = 0;
	}
}