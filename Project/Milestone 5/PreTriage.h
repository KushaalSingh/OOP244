/*
Citation and Sources...
Final Project Milestone 1
Module: PreTriage
Filename: PreTriage.h
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

#ifndef SENECA_PRE_TRIAGE_H
#define SENECA_PRE_TRIAGE_H

#include <fstream>
#include "Menu.h"
#include "TestPatient.h"
#include "TriagePatient.h"

namespace seneca {

	const int MAX_PATIENTS = 100;

	class PreTriage {
	private:
		Time m_avgContaigenTime;
		Time m_avgTriageTime;
		Patient* m_patients[MAX_PATIENTS]{};
		char* m_dataFile;
		int m_numPatients;

		Time getWaitTime(const Patient& src) const;
		void setAverageWaitTime(const Patient& src);
		int indexOfFirstInLine(char type);
		void load();
		void save();
		void Register();
		void admit();
		void lineup() const;

	public:
		PreTriage(const char* file);
		~PreTriage();
		void run();
	};
	// Can't put it in module. Getting error LNK2019.
	template <typename type>
	void removeDynamicElement(type* array[], int index, int& size);

}


#endif
