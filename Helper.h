//============================================================================
// Name        :Helper.h, for DeltaAirlines.cpp
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description : This is a helper file for DeltaAirlines.cpp
//               This file stores protoypes fro DeltaAirlines.cpp
//============================================================================

#ifndef HELPER_H_
#define HELPER_H_

#include <string>
#include "Passenger.h"

using namespace std;

char operationPrompt(); //prompts user to select task and returns user input
int selectFlight(int const FlightNo); //converts user's desired flightNo into 0/1/2/3 used to access array indexes
int inputValidity(string name); //checks if user has entered a valid input for name
int getFlightInput();//evaluate's users input for flight number

#endif /* HELPER_H_ */
