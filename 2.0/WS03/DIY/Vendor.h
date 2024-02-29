#include "Icecream.h"

#ifndef VENDOR_H
#define VENDOR_H

namespace seneca {
	
	class Vendor {
	private:
		int numberOfOrders;
		Icecream* icecream;
		double subTotal;
		double tax;
		double total;
	public:
		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();
	};

	void displayHeader();
}

#endif
