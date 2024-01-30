#include "Train.h"

namespace sdds {

void Train::initialize() {
  trainName = nullptr;
  numPassenger = -1;
  departureTime = -1;
}

bool Train::validTime(int value) const {
  return ((value >= MIN_TIME) && (value <= MAX_TIME) && (value % 100 < 60));
}

bool Train::validNoOfPassengers(int value) const {
  return ((value > 0) && (value <= MAX_NO_OF_PASSENGERS));
}

void Train::set(const char* name) {
  finalize();
  if (name != nullptr && name[0] != '\0') {
    trainName = new char((int)strlen(name) + 1);
    strcpy(trainName, name);
  }
}

void Train::set(int noOfPassengers, int departure) {
  if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
    numPassenger = noOfPassengers;
    departureTime = departure;
  }
		else {
    numPassenger = -1;
    departureTime = -1;
  }
}

void Train::set(const char* name, int noOfPassengers, int departure) {
  set(name);
  set(noOfPassengers, departure);
}

void Train::finalize() {
  delete[] trainName;
  trainName = nullptr;
}

bool Train::isInvalid() const {
  return (trainName == nullptr || numPassenger == -1 || departureTime == -1);
}

int Train::noOfPassengers() const {
  return numPassenger;
}

const char* Train::getName() const {
  return (trainName ? trainName : "No Name");
}

int Train::getDepartureTime() const {
  return departureTime;
}

void Train::display() const {
  if (!isInvalid()) {
    std::cout << "NAME OF THE TRAIN : " << getName() << std::endl;
    std::cout << "NUMBER OF PASSENGERS  : " << noOfPassengers() << std::endl;
    std::cout << "DEPARTURE TIME        : " << getDepartureTime() << std::endl;
  }
		else std::cout << "Train is in invalid state" << std::endl;
}
}