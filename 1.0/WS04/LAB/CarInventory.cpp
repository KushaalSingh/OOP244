#include "CarInventory.h"

namespace sdds {

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model) {
		resetInfo();
		memoryAllocation(*this, type, brand, model);
		numberAllocation(*this, 0, 0, 0.00);
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();
		memoryAllocation(*this, type, brand, model);
		numberAllocation(*this, year, code, price);
	} 

	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();
		memoryAllocation(*this, type, brand, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}

	void CarInventory::printInfo() const {
		std::cout << "| ";
		std::cout.width(10);
		std::cout.setf(std::ios::left);
		std::cout << m_type << " | ";
		std::cout.width(16);
		std::cout << m_brand << " | ";
		std::cout.width(16);
		std::cout << m_model << " | ";
		std::cout.width(4);
		std::cout.unsetf(std::ios::left);
		std::cout << m_year << " | ";
		std::cout.width(4);
		std::cout.setf(std::ios::right);
		std::cout << m_code << " | ";
		std::cout.width(9);
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << m_price << " |" << std::endl;
		std::cout.unsetf(std::ios::right);
		std::cout.unsetf(std::ios::fixed);
	}
	
	bool CarInventory::isValid() const {
		return validType(m_type) && validBrand(m_brand) && validModel(m_model) && validYear(m_year) && validCode(m_code) && validPrice(m_price);
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool valid_1 = validType(m_type) && validBrand(m_brand) && validModel(m_model) && validYear(m_year);
		bool valid_2 = validType(car.m_type) && validBrand(car.m_brand) && validModel(car.m_model) && validYear(car.m_year);
		if (!(valid_1 && valid_2)) return false;
		bool sameType = (strcmp(m_type, car.m_type) == 0);
		bool sameBrand = (strcmp(m_brand, car.m_brand) == 0);
		bool sameModel = (strcmp(m_model, car.m_model) == 0);
		bool sameMake = (m_year == car.m_year);
		return sameType && sameBrand && sameModel && sameMake;
	}

	int find_similar(CarInventory car[], const int num_cars) {
		int i, k;
		for (i = 0; i < num_cars; i++) {
			for (k = i + 1; k < num_cars; k++) {
				if (car[i].isSimilarTo(car[k])) {
					return i;
				}

			}
			
		}
		return -1;
	}

	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	void memoryAllocation(CarInventory& car, const char* type, const char* brand, const char* model) {
		car.m_type = new char[strlen(type) + 1];
		strcpy(car.m_type, type);
		car.m_brand = new char[strlen(brand) + 1];
		strcpy(car.m_brand, brand);
		car.m_model = new char[strlen(model) + 1];
		strcpy(car.m_model, model);
	}

	void numberAllocation(CarInventory& car, int year, int code, double price) {
		if (validYear(year)) car.m_year = year;
		else car.m_year = 2022;
		if (validCode(code)) car.m_code = code;
		else car.m_code = 100;
		if (validPrice(price)) car.m_price = price;
		else car.m_price = 1.00;
	}

	bool validType(const char* type) {
		return type != nullptr;
	}

	bool validBrand(const char* brand) {
		return brand != nullptr;
	}

	bool validModel(const char* model) {
		return model != nullptr;
	}

	bool validYear(int year) {
		return year >= MIN_MAKE_YEAR;
	}

	bool validCode(int code) {
		return (code > 99 && code < 1000);
	}

	bool validPrice(double price) {
		return price > 0.00;
	}
}