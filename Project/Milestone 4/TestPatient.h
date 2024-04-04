#ifndef SENECA_TEST_PATIENT_H
#define SENECA_TEST_PATIENT_H

#include "Patient.h"

namespace seneca {

	extern int nextTestTicket;
	
	class TestPatient : public Patient {
	private:

	public:
		TestPatient();
		char type() const override;
		std::ostream& write(std::ostream& out) const override;
	};



}


#endif
