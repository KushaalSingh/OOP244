#include<iostream>

using namespace std;

class Wind {

	int category;

public:

	Wind(int cat = 3) {

		category = cat;

		cout << "1." << cat << endl;

	}

	virtual void increase(int amount) {

		category += amount;

		cout << "A. " << category << endl;

	}

	void operator++() {

		++category;

		cout << "B. " << category << endl;

	}

	virtual ~Wind() {

		cout << "C. " << category << endl;

	}

};

class Tornado :public Wind {

	double velocity;

public:

	Tornado(int cat, double vel) :Wind(cat) {

		velocity = vel;

		cout << "2. " << vel << endl;

	}

	virtual void increase(int value) {

		velocity += value;

		cout << "X. " << velocity << endl;

	}

	void operator++() {

		Wind::operator++();

		velocity += 20;

		cout << "Y. " << endl;

	}

	~Tornado() {

		cout << "Z. " << velocity << endl;

	}

};

int main() {

	Wind* wind_array[2];

	wind_array[0] = new Tornado(7, 66.5);

	wind_array[1] = new Wind(5);

	for (int i = 0; i < 2; i++) {

		wind_array[i]->increase(5);

		++(*wind_array[i]);

	}

	for (int i = 0; i < 2; i++)

		delete wind_array[i];

	return 0;

}