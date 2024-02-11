#include "Room.h"

namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		room.m_guests = new Guest[numberOfGuests];
		strcpy(room.m_roomNumber, roomNumber);
	}

	void print(const Room& room) {
		int i;
		std::cout << "Room number" << room.m_roomNumber << ": " << std::endl;
		for (i = 0; i < room.m_noOfGuests; i++) {
			std::cout << "    ";
			print(room.m_guests[i]);
		}
	}







}