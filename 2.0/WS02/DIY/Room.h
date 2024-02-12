#include "Guest.h"

#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H

namespace seneca {
	
	typedef struct {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	} Room;

	void set(Room& room, int numberOfGuests, const char* roomNumber);
	void print(const Room& room);
}

#endif
