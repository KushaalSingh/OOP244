#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {
#ifndef TRAIN_H
#define TRAIN_H

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

class Train {
private:
  char* trainName;	// Name of the train (Dynamically allocated).
  int numPassenger;	// Number of passanger.
  int departureTime;	// Departure time of the train in military format.

public:
  void initialize();
  bool validTime(int value) const;
  bool validNoOfPassengers(int value) const;
  void set(const char* name);
  void set(int noOfPassengers, int departure);
  void set(const char* name, int noOfPassengers, int departure);
  void finalize();
  bool isInvalid() const;
  int noOfPassengers() const;
  const char* getName() const;
  int getDepartureTime() const;
  void display() const;
};
}

#endif