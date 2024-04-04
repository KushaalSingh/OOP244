/*
Citation and Sources...
Final Project Milestone 1
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include "TriagePatient.h"

namespace seneca {

	int nextTriageTicket = 1;
	
	TriagePatient::TriagePatient() : Patient(nextTriageTicket++), m_symptoms(nullptr) {}

	char TriagePatient::type() const {
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& out) const {
		if (&out == &std::cout) out << "TRIAGE" << std::endl;
		Patient::write(out);
		if (&out == &std::clog) out << "Symptoms: " << m_symptoms << std::endl;
		else out << "," << m_symptoms << std::endl;
		return out;
	}

	std::istream& TriagePatient::read(std::istream& in) {
		delete[] m_symptoms;
		Patient::read(in);
		if (&in != &std::cin) {
			char symptoms[SYM_LEN];
			in.ignore(',');
			if (!in.get(symptoms, (SYM_LEN - 1), '\n')) {
				deleteSymp();
				return in;
			}
			U.allocStringCopy(m_symptoms, symptoms);
		}
		return in;
	}

	TriagePatient::~TriagePatient() {
		deleteSymp();
	}

	void TriagePatient::deleteSymp() {
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}

}