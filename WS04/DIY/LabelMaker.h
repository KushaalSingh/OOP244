#include "Label.h"

#ifndef LABEL_MAKER_H
#define LABEL_MAKER_H

namespace sdds {
	
	class LabelMaker {
	private:
		Label* label;
		int numLabels;

	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
		void resetLabel();
	};
}


#endif
