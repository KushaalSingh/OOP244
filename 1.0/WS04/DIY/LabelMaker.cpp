#include "LabelMaker.h"

namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		resetLabel();
		label = new Label[noOfLabels];
		numLabels = noOfLabels;
	}

	void LabelMaker::readLabels() {
		int i;
		for (i = 0; i < numLabels; i++) {
			std::cout << "Enter label number " << i + 1 << std::endl << "> ";
			label[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		int i;
		for (i = 0; i < numLabels; i++) {
			label[i].printLabel();
			std::cout << std::endl;
		}
	}

	LabelMaker::~LabelMaker() { resetLabel(); }

	void LabelMaker::resetLabel() {
		delete[] label;
		label = nullptr;
	}
}