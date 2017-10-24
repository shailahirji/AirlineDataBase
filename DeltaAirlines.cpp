//============================================================================
// Name        : DeltaAirlines.cpp
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description : This is an app that runs for delta airlines and allows them to keep records of passengers on 4 of their flights
//               This app allows delta airlines to perform the following tasks on their data records
//                      -Add passenger in ascending order based off passenger last name
//                      -Search for specific passengers via their last name and First name
//                      -List the names and contact information of passengers on selected flights
//                      -Delete Passenger, remove passenger's bookings on selected flight via their last name and first name
//============================================================================

#include <iostream>
#include <string>
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include "Helper.h"
#include <sstream>

using namespace std;

int main() {

	OrderedLinkedList<Passenger> *pFlights =
			new OrderedLinkedList<Passenger> [4]; //array holding OLL of passengers

	cout << "*** DELTA AIRLINES***" << endl;
	cout << "Please choose an operation:" << endl;

	//----------------- to do always------------------//
	bool run = true;
	char userRequest;
	OrderedLinkedList<Passenger> *list;
	while (run) // to exit, user enters q.
	{
		userRequest = operationPrompt(); //prompts user to select task

		switch (userRequest) {

		case 'A':
		case 'a': {

			int flightNo = getFlightInput(); //gets valid flight number from user
			string fname, lname, address, phone;

			cout << "Enter first name:";
			cin.ignore();
			getline(cin, fname);

			while (!inputValidity(fname)) { //assure's user enters valid characters
				cout << "\n Invalid First Name. Please reenter:";
				getline(cin, fname);
				cin.ignore();
			}

			cout << "Enter last name:";
			getline(cin, lname);

			while (!inputValidity(lname)) {
				cout << "\n Invalid Last Name. Please reenter:";
				getline(cin, lname);
				cin.ignore();
			}

			cout << "Enter Phone Number:";
			getline(cin, phone);

			cout << "Enter Address:";
			getline(cin, address);

			//get access to flight's assigned OLL, selectFlight function returns the corresponding array index to flightNo
			//100/200/300/400 -> 0/1/2/3 respectively

			list = &pFlights[selectFlight(flightNo)];
			Passenger person(fname, lname, phone, address, flightNo);
			list->insert(person);			//adds passenger to flight's list

		}
			break;

		case 'S':
		case 's': {
			//search for a specific passenger

			string fname, lname;

			cout << "Enter First Name:";
			getline(cin, fname);
			while (!inputValidity(fname)) {
				cout << "\n Invalid First Name. Please reenter:";
				getline(cin, fname);
			}

			cout << "Enter last Name:";
			getline(cin, lname);
			while (!inputValidity(lname)) {
				cout << "\n Invalid last Name. Please reenter:";
				getline(cin, lname);
			}

			Passenger person(fname, lname);

			for (int i = 0; i < 4; i++) { //searches each flight OLL
				list = &pFlights[i];
				person = list->search(person); //calls search function from OLL

				if (person.getPassengerAddress() != "") { //passenger has an address, i.e exists
					print(person); //returns passenger's information
					person.setPassengerAddress(""); // this is used as a flag to enable checking all flgihts for this passenger
				}
			}
			if (person.getPassengerAddress() == ""
					&& person.getPassengerPhone() == "") //if passenger doesnt exist
				cout << "Passenger is not on any flights" << endl;

		}
			break;
		case 'D':
		case 'd': {
			//delete passenger's booking

			int flightNo = getFlightInput(); //gets valid flight number from user

			string lname, fname;

			cout << "Enter last Name: ";
			cin.ignore();
			getline(cin, lname);
			while (!inputValidity(lname)) {
				cout << "\n Invalid Last Name. Please reenter:";
				getline(cin, lname);
			}

			cout << "Enter first Name: ";
			getline(cin, fname);
			while (!inputValidity(fname)) {
				cout << "\n Invalid first Name. Please reenter:";
				getline(cin, fname);
			}

			Passenger person(fname, lname, "", "", flightNo);

			list = &pFlights[selectFlight(flightNo)]; //get flight's OLL
			person = list->deleteNode(person); //if passenger found, update their contact info

			if (person.getPassengerAddress() != "") { //if address isn't empty, passenger was found and deleted
				cout << "The Passenger is deleted" << endl;
			}
		}
			break;
		case 'L':
		case 'l': {

			//lists passenger's that have bookings on selected flight

			int flightNo = getFlightInput(); //gets valid flight number from passengers

			list = &pFlights[selectFlight(flightNo)]; //list var now refers to the flight selected by user
			if (list->isEmpty())
				cout << "No bookings for this flight" << endl;
			cout << *list << endl;

		}
			break;
		case 'Q':
		case 'q': {
			run = false; //flag
			return 0;
		}
			break;
		default:
			cout << "\nPlease, try again.\n";
		}
	}

	return 0;
}

/*
 * Prints operation prompt
 * returns char selected by user
 */
char operationPrompt() {
	char userWants;
	cout << " A (Add) | S (Search) | D (Delete) | L (List) | Q(Quit): ";
	cin >> userWants;
	cin.ignore();
	return userWants;

}

/*
 * Converts the user's desired flight number 100/200/300/400 to array Index 0/1/2/3 respectively
 * returns 0/1/2/3
 */
int selectFlight(int const flightNo) {

	switch (flightNo) {
	case 100:
		return 0;

	case 200:
		return 1;

	case 300:
		return 2;

	case 400:
		return 3;

	default:
		return -1;
	}

}

/*
 * Checks validity of user's input for names
 * returns 1 if name contains letters only
 * returns 0 if name contains characters other than letters
 */
int inputValidity(string name) {
	char c;

	// Iterate through the string one letter at a time.
	for (int i = 0; i < name.length(); i++) {
		c = name.at(i);         // Get a char from string
		// if it's NOT within these bounds, then it's not a character
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
			return 0;		//number used instead of alphabet
		}
	}

	return 1;		//all ok!
}

/*
 * This method prompts user to enter flight number
 * Method checks validity of flight number by making sure its only the following numbers, 100,200,300,400
 * returns the array index based on respective flight number selected by user
 */
int getFlightInput() {
	//add passengers to flight
	string userInput;
	int flightNo;		//user's flight number input
	cout << "Enter Flight Number:";
	cin >> userInput;

	while (inputValidity(userInput)) {	//if input for flight number are letters
		cout << "\n Invalid flight number. Please reenter:";
		cin >> userInput;
	}

	flightNo = atoi(userInput.c_str());		//convert userInput to int value

	while (flightNo != 100 && flightNo != 200 && flightNo != 300
			&& flightNo != 400) {
		cout << "\n Invalid flight number. Please reenter:";
		cin >> flightNo;

	}
	return flightNo;
}
