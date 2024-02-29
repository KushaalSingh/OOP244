#include "Icecream.h"

#ifndef VENDOR_H
#define VENDOR_H

namespace seneca {
	
	class Vendor {
	private:
		int numberOfOrders;
		Icecream* icecream;
	public:
		void setEmpty();
		void takeOrders();
	};

	void displayHeader();
}

#endif
