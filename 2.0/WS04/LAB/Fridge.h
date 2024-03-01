#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef FRIDGE_H
#define FRIDGE_H 
 
#define NAME_LEN 20
#define FRIDGE_CAP 3

namespace seneca {

	class Fridge {
	private:
		Food m_foods[FRIDGE_CAP];
		int m_numFoods;
		char* m_model;
		void setEmpty();
	public:
		Fridge();
		Fridge(Food farr[], int nf, const char* mod);
		~Fridge();
	};

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

	bool notEmptyString(const char* str);

}

#endif 
