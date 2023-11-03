#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <cstring>

namespace sdds {

#define MIN_MAKE_YEAR 1990

	class CarInventory {
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model);
		CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;

		friend void memoryAllocation(CarInventory& car, const char* type, const char* brand, const char* model);
		friend void numberAllocation(CarInventory& car, int year, int code, double price);
	};
	
	int find_similar(CarInventory car[], const int num_cars);
	bool validType(const char* type);
	bool validBrand(const char* brand);
	bool validModel(const char* model);
	bool validYear(int year);
	bool validCode(int code);
	bool validPrice(double price);
}