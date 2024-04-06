#include "PreTriage.h"

namespace seneca {

	PreTriage::PreTriage(const char* file) : m_contaigenTest(15), m_triagePatients(5) {
		for (int i = 0; i < MAX_PATIENTS; i++) m_patients[i] == nullptr;
		U.allocStringCopy(m_dataFile, file);
		
		// load(); FUNCTION NEEDS TO BE IMPLEMENTED

	}

	PreTriage::~PreTriage() {
		// save(); FUNCTION NEEDS TO BE IMPLEMENTED
		for (int i = 0; i < MAX_PATIENTS; i++) delete[] m_patients[i];
		delete[] m_dataFile;
	}

}