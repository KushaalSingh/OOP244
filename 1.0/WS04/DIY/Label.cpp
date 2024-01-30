#include "Label.h"

namespace sdds {

	Label::Label() {
		loadFrame(nullptr);
		_content = nullptr;
	}

	Label::Label(const char* frameArg) {
		loadFrame(frameArg);
		_content = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		loadFrame(frameArg);
		text(content);
	}

	Label::~Label() {
		resetFrame();
		resetContent();
	}

	void Label::loadFrame(const char* frameArg) {
		if (frameArg == nullptr) {
			_frame = new char[9];
			strcpy(_frame, "+-+|+-+|");
		}
		else {
			_frame = new char[(int)strlen(frameArg) + 1];
			strcpy(_frame, frameArg);
		}
	}

	Label& Label::text(const char* contentArg) {
		int i;
		resetContent();
		if (contentArg == nullptr) {
			_content = new char[(int)strlen("*NO CONTENT*") + 1];
			strcpy(_content, "*NO CONTENT*");
		}
		else if ((int)strlen(contentArg) >= MAX_CHAR) {
			_content = new char[MAX_CHAR + 1];
			for (i = 0; i < MAX_CHAR; i++) _content[i] = contentArg[i];
		}
		else {
			_content = new char[(int)strlen(contentArg) + 1];
			strcpy(_content, contentArg);
		}
		return *this;
	}

	std::istream& Label::readLabel() {
		char userInput[MAX_CHAR + 1];
		std::cin.getline(userInput, MAX_CHAR);
		text(userInput);
		return std::cin;
	}

	std::ostream& Label::printLabel() const {
		int i;
		int width = (_content == nullptr) ? 0 : (int)strlen(_content);
		if (!width) return std::cout;
		std::cout << _frame[0];
		for (i = 0; i < width + 2; i++) std::cout << _frame[1];
		std::cout << _frame[2] << std::endl;
		std::cout << _frame[7];
		for (i = 0; i < width + 2; i++) std::cout << " ";
		std::cout << _frame[3] << std::endl;
		std::cout << _frame[7] << " ";
		std::cout << _content << " ";
		std::cout << _frame[3] << std::endl;
		std::cout << _frame[7];
		for (i = 0; i < width + 2; i++) std::cout << " ";
		std::cout << _frame[3] << std::endl;
		std::cout << _frame[6];
		for (i = 0; i < width + 2; i++) std::cout << _frame[5];
		std::cout << _frame[4];

		return std::cout;
	}

	void Label::resetFrame() {
		if (_frame != nullptr) {
			delete[] _frame;
			_frame = nullptr;
		}
	}

	void Label::resetContent() {
		if (_content != nullptr) {
			delete[] _content;
			_content = nullptr;
		}
	}

}