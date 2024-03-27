/*
Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.cpp
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Patient.h"
#include "Utils.h"

namespace seneca {

	Patient::Patient(int ticketNum) : m_ticket(ticketNum) {
		m_name = nullptr;
		m_OHIP = 0;
	}

	Patient::Patient(const Patient& src) : m_ticket(src.m_ticket) {
		deleteName();
		copyString(m_name, src.m_name, NAME_LEN);
		m_OHIP = src.m_OHIP;
	}

	Patient::~Patient() {
		deleteName();
	}

	void Patient::deleteName() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::operator== (char ch) const {
		return (type() == ch);
	}


}