#ifndef SENECA_PRE_TRIAGE_H
#define SENECA_PRE_TRIAGE_H

#include <fstream>
#include "Patient.h"

namespace seneca {

	const int MAX_PATIENTS = 100;

	class PreTriage {
	private:
		Time m_contaigenTest;
		Time m_triagePatients;
		Patient* m_patients[MAX_PATIENTS];
		char* m_dataFile;
		int m_numPatients;

	public:
		PreTriage(const char* file);
		~PreTriage();
	};


}


#endif // !SENECA_PRE_TRIAGE_H
