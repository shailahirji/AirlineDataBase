//============================================================================
// Name        :Passenger.h
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description :This class contains implementation of Passenger object prototypes from Passenger.h
//============================================================================

#include "Passenger.h"
#include <iostream>

using namespace std;

//constructor
Passenger::Passenger(string Fname, string Lname, string phone, string address,
		int flightNo) {
	//assign passed values
	_fName = Fname;
	_lName = Lname;
	_phone = phone;
	_address = address;
	_flightNo = flightNo;

}

Passenger::~Passenger() {

}

void Passenger::setPassengerFName(string Fname) {
	_fName = Fname;
}

void Passenger::setPassengerLName(string Lname) {
	_lName = Lname;
}

void Passenger::setPassengerPhone(string phone) {
	_phone = phone;
}

void Passenger::setPassengerAddress(string address) {
	_address = address;
}

void Passenger::setPassengerFlightNo(int flightNo) {
	_flightNo = flightNo;
}

string Passenger::getPassengerFName() {
	return _fName;

}

string Passenger::getPassengerLName() {
	return _lName;

}

string Passenger::getPassengerPhone() {
	return _phone;
}

string Passenger::getPassengerAddress() {
	return _address;
}

int Passenger::getPassengerFlightNo() {
	return _flightNo;
}

/*
 * Friend function that print's passenger information flight passengers are to be listed
 */
void print(Passenger &person) {

	cout << "Flight Number:" << person.getPassengerFlightNo() << endl;
	cout << "First Name:" << person.getPassengerFName() << endl;
	cout << "Last Name:" << person.getPassengerLName() << endl;
	cout << "Address:" << person.getPassengerAddress() << endl;
	cout << "Phone:" << person.getPassengerPhone() << endl;
}

/*
 * compare two passengers via their fnmae and lname
 * returns bool
 */
bool Passenger::operator==(const Passenger &p1) {

	return (p1._fName == this->_fName && p1._lName == this->_lName);

}

/*
 * compare two passengers via their fnmae and lname
 * returns bool
 */
bool Passenger::operator!=(const Passenger &p1) {

	return (p1._fName != this->_fName
			&& (p1._lName != this->_lName || p1._lName == this->_lName));

}

/*
 * compare two passengers via their lname only
 * returns bool
 */
bool Passenger::operator<(const Passenger &p1) {

	return (this->_lName < p1._lName);

}

/*
 * compare two passengers via their lname only
 * returns bool
 */
bool Passenger::operator>(const Passenger &p1) {

	return (this->_lName > p1._lName);

}

/*
 * Enables printing of passenger object to console using cout<<
 */
ostream &operator<<(ostream &os, Passenger &person) {

	os << person.getPassengerFName() << " " << person.getPassengerLName()
					<< " [" << person.getPassengerAddress() << "] ["
					<< person.getPassengerPhone() << "] ";

	return os;
}
