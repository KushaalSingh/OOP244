/*
Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.cpp
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
#include "IOAble.h"

namespace seneca {

	std::ostream& IOAble::operator<<(std::ostream& out) {
		return write(out);
	}

	std::istream& IOAble::operator>>(std::istream& in) {
		return read(in);
	}
}