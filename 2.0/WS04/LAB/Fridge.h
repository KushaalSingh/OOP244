#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef FRIDGE_H
#define FRIDGE_H

#define NAME_LEN 20
#define FRIDGE_CAP 3

namespace seneca {


	class Food {
	private:
		char m_name[NAME_LEN]{};
		int m_weight{};
	public:
		Food();
		Food(const char* nm, int wei);
		const char* name()const;
		int weight()const;
	};


}

#endif