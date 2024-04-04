#include "TestPatient.h"

namespace seneca {

	int nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(nextTestTicket++) {}

	char TestPatient::type() const {
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& out) const {
		if (&out == &std::cout) {
			out << "Contagion TEST" << std::endl;
			Patient::write(out);
		}
		return out;
	}

	std::istream& read(std::istream& in) {

	}

}