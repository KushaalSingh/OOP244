#include <iostream>

#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

namespace seneca {

	typedef struct {
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	} Guest;
}

#endif