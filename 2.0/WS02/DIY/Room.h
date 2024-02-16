#include "Guest.h"

#ifndef ROOM_H
#define ROOM_H

namespace wrk {

	typedef struct {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	} Room;

	void set(Room& room, int numberOfGuests, const char* roomNumber);
	void print(const Room& room);
	void book(Room& room);
	void vacate(Room& room);
}
#endif
