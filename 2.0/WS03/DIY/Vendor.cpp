#include "Vendor.h"

namespace seneca {

	void Vendor::setEmpty() {
		numberOfOrders = 0;
		subTotal = 0.00;
		icecream = nullptr;
		tax = 0.00;
		total = 0.00;
	}

	void Vendor::takeOrders() {
		int i;
		displayHeader();
		setEmpty();
		numberOfOrders = getInt("How many Icecreams?", 100, 1);
		icecream = new Icecream[numberOfOrders];
		for (i = 0; i < numberOfOrders; i++) {
			std::cout << "Order number " << i + 1 << ":" << std::endl;
			icecream[i].getOrder();
			subTotal += icecream[i].returnTotal();
		}
		tax = subTotal * 0.13;
		total = tax + subTotal;
	}

	void Vendor::displayOrders() {
		int i;
		std::cout << "********** Order Summary **********" << std::endl;
		for (i = 0; i < numberOfOrders; i++) {
			std::cout << "Order No: " << i + 1 << ":" << std::endl;
			icecream[i].printOrder();
			std::cout << std::endl;
		}
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "Price:"; displayDouble(subTotal, 29);
		std::cout << "Tax:"; displayDouble(tax, 31);
		std::cout << "Total Price ($):"; displayDouble(total, 19);
	}

	void Vendor::clearData() {
		int i;
		for (i = 0; i < numberOfOrders; i++) icecream[i].deallocate();
		delete[] icecream;
	}

	void displayHeader() {
		std::cout << "Seneca Icecream shop" << std::endl;
		std::cout << "          @" << std::endl;
		std::cout << "        (' .)" << std::endl;
		std::cout << "       (*.`. )" << std::endl;
		std::cout << "        \\###/" << std::endl;
		std::cout << "         \\#/" << std::endl;
		std::cout << "          V" << std::endl;
	}


}