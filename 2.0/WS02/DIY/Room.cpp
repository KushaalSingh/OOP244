#include "Room.h"

namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		room.m_guests = new Guest[numberOfGuests];
		strcpy(room.m_roomNumber, roomNumber);
	}








}