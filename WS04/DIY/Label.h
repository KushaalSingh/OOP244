#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef LABEL_H
#define LABEL_H

#define MAX_CHAR 70

namespace sdds {
	
	class Label {
	private:
		char* _frame;
		char* _content;
		
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void loadFrame(const char* frameArg);
		Label& text(const char* contentArg);
		std::istream& readLabel();
		std::ostream& printLabel() const;
		void resetFrame();
		void resetContent();
	};

}

#endif
