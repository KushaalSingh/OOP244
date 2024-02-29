#include "Icecream.h"

namespace seneca {

	void Icecream::getOrder() {
		setOrderToEmpty();
		displayMenu();

		assignFlavour();
		numberOfScoops = getInt("Number of Scoops (max 3)", 3, 1);
		vanillaWafer = getvanillaWafer();
		total = calculateTotal(numberOfScoops, isChoco, vanillaWafer);
	}

	void Icecream::printOrder() {
		std::cout << "Order details:                Price" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "Number of scoops, " << numberOfScoops << " total:"; displayDouble(numberOfScoops * 5.00, 9);
		if (isChoco) {
			std::cout << "Chocolate flavour:";
			displayDouble(numberOfScoops * 1.00, 17);
		}
		else std::cout << flavour << " flavour" << std::endl;
		std::cout << "Vanilla Wafer:";
		if (vanillaWafer) displayDouble(5.00, 21);
		else displayDouble(0.00, 21);
		std::cout << "Price:";
		displayDouble(total, 29);
	}

	void Icecream::setOrderToEmpty() {
		flavour = nullptr;
		numberOfScoops = 0;
		total = 0.00;
		isChoco = false;
		vanillaWafer = false;
	}

	void displayMenu() {
		std::cout << "Select flavour:" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << "1: Chocolate" << std::endl;
		std::cout << "2: Strawberry" << std::endl;
		std::cout << "3: Mango" << std::endl;
		std::cout << "4: Tutti fruit" << std::endl;
		std::cout << "5: Almond crunch" << std::endl;
		std::cout << "----------------" << std::endl;
	}

	void Icecream::assignFlavour() {
		int flavourSelection = getInt(nullptr, 5, 1);
		switch (flavourSelection) {
		case 1:
			flavour = new char[strlen("Chocolate") + 1];
			strcpy(flavour, "Chocolate");
			isChoco = true;
			break;
		case 2:
			flavour = new char[strlen("Strawberry") + 1];
			strcpy(flavour, "Strawberry");
			break;
		case 3:
			flavour = new char[strlen("Mango") + 1];
			strcpy(flavour, "Mango");
			break;
		case 4:
			flavour = new char[strlen("Tutti fruit") + 1];
			strcpy(flavour, "Tutti fruit");
			break;
		case 5:
			flavour = new char[strlen("Almond crunch") + 1];
			strcpy(flavour, "Almond crunch");
			break;
		}
	}

	int getInt(const char* statement, int uprBnd, int lwrBnd) {
		int input, stst = 1;
		if (statement != nullptr) std::cout << statement << std::endl;
		while (stst) {
			std::cout << "> ";
			if (!(std::cin >> input)) {
				std::cout << "Invalid entry, retry" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else if (input > uprBnd || input < lwrBnd) std::cout << "Invlid value(" << lwrBnd << "<=val<=" << uprBnd << ")" << std::endl;
			else stst = 0;
		}
		return input;
	}
	
	bool getvanillaWafer() {
		char input[256];
		std::cout << "Vanilla wafer cone?" << std::endl;
		std::cout << "(Y)es/(N)o ";
		std::cin.ignore();
		while (true) {
			std::cout << "> ";
			std::cin.getline(input, 256);
			if (validYesOrNo(input)) {
				if (input[0] == 'y' || input[0] == 'Y') return true;
				else if (input[0] == 'n' || input[0] == 'N') return false;
			}
			else std::cout << "Only Y or N are acceptable:" << std::endl;
		}
	}

	void Icecream::deallocate() {
		delete[] flavour;
	}

	double calculateTotal(int numberOfScoops, bool isChoco, bool vanillaWafer) {
		double total = 0;
		total += numberOfScoops * 5.00;
		if (isChoco) total += numberOfScoops * 1.00;
		if (vanillaWafer) total += 5.00;
		return total;
	}

	void displayDouble(double num, int _width) {
		std::cout.setf(std::ios::fixed);
		std::cout.setf(std::ios::right);
		std::cout.precision(2);
		std::cout.width(_width);
		std::cout << num << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout.unsetf(std::ios::right);
	}

	bool validYesOrNo(const char* str) {
		return (str[0] == 'y' || str[0] == 'Y' || str[0] == 'n' || str[0] == 'N') && str[1] == '\0';
	}

	double Icecream::returnTotal() {
		return total;
	}

}