#include "Vendor.h"

namespace seneca {

	void Vendor::setEmpty() {
		numberOfOrders = 0;
		icecream = nullptr;
	}

	void Vendor::takeOrders() {
		numberOfOrders = getInt("How many Icecreams?", 100, 1);
		icecream = new Icecream[numberOfOrders];

	}

	void displayHeader() {
		std::cout << "Seneca Icecream shop" << std::endl;
		std::cout << "          @" << std::endl;
		std::cout << "        (' .)" << std::endl;
		std::cout << "       (*.`. )" << std::endl;
		std::cout << "        \###/" << std::endl;
		std::cout << "         \#/" << std::endl;
		std::cout << "          V" << std::endl;
	}

}