//============================================================================
// Name        :Passenger.h
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description :This class contains prototypes for an object of type passenger.It contains the following functions:
//             :Getter and setters for all variables of Passenger object
//             :overide's comparison operators enabling comparison between objects of passenger type
//             :overide's os << operator to enable console printing of passenger object
//             :Passenger object destructor
//============================================================================

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include<string>

using namespace std;

class Passenger {
private:
	string _fName;
	string _lName;
	string _phone;
	string _address;
	int _flightNo;

public:

	Passenger(string Fname = "", string Lname = "", string phone = "",
			string address = "", int flightNo = -1); //4 pm
	void setPassengerFName(string Fname);

	void setPassengerLName(string Lname);

	void setPassengerPhone(string phone);

	void setPassengerAddress(string address);

	void setPassengerFlightNo(int flightNo);

	string getPassengerFName();

	string getPassengerLName();

	string getPassengerPhone();

	string getPassengerAddress();

	int getPassengerFlightNo();

	bool operator==(const Passenger &person1);

	bool operator!=(const Passenger &person1);

	bool operator<(const Passenger &person1); //less than

	bool operator>(const Passenger &person1); //greater than

	friend void print(Passenger &);

	friend ostream &operator<<(ostream &os, Passenger &person);

	virtual ~Passenger();

};

#endif /* PASSENGER_H_ */

