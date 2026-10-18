#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

//!<------ Passenger class with all passenger data ------>!
class Plane;
class Passenger {
	string id;
	string name;
	string email;
	int flight;
	string ticketType;
	string destination;
	int seat_row;
	int seat_col;
	friend class Plane;
	friend class Seat;

public:
//!<------ Passenger class functions to set passenger data ------>!
	void setID()
	{
		string id;
		getline(cin, id);
		this->id = id;

	}
	void setName()
	{
		string Name;
		getline(cin, Name);
		for (int i = 0; i<Name.size(); ++i)
			Name[i] = toupper(Name[i]);
		this->name = Name;
	}
	void setEmail()
	{
		string email;
		getline(cin, email);
		this->email = email;
	}
	void setTicketType()
	{
		string ticket;
		getline(cin, ticket);
		for (int i = 0; i < ticket.size(); ++i)
			ticket[i] = toupper(ticket[i]);
		this->ticketType = ticket;
	}
	void setDestination()
	{
		string dest;
		getline(cin, dest);
		for (int i = 0; i<dest.size(); ++i)
			dest[i] = toupper(dest[i]);
		this->destination = dest;
	}
	void setFlight()
	{
		int flight;
		cin >> flight;
		cin.ignore();
		this->flight = flight;
	}
	void getData(string id, string fname, string lname, string email, string destination, int flight, string ticket, int row, int col)
	{
		this->id = id;
		this->name = (fname + " " + lname);
		this->email = email;
		this->destination = destination;
		this->flight = flight;
		this->ticketType = ticket;
		this->seat_row = row;
		this->seat_col = col;
	}

//!<------ Passenger class functions to return passenger data ------>!
	string viewID()
	{
		return id;
	}
	int viewFlight()
	{
		return flight;
	}
	string viewDestination()
	{
		return destination;
	}
	string viewName()
	{
		return name;
	}
	string viewEmail()
	{
		return email;
	}
	string viewTicketType()
	{
		return ticketType;
	}
	int viewSeatRow()
	{
		return seat_row;
	}
	int viewSeatCol()
	{
		return seat_col;
	}


//!<------ Passenger class functions to print passenger data ------>!
	void printName()
	{
		cout << name << endl;
	}
	void printDestination()
	{
		cout << destination;
	}
	void printTicketType()
	{
		cout << ticketType << endl;
	}
	void printSeat()
	{
		cout << seat_row << "  " << seat_col << endl;
	}
	void printFullData()
	{
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Email : " << email << endl;
		cout << "Destination : " << destination << endl;
		cout << "Flight : " << flight << endl;
		cout << "Ticket Type : " << ticketType << endl;
		cout << "Seat : " << seat_row << ' ' << seat_col << endl;
	}
	
	
	friend ostream& operator << (ostream& out, const Passenger& obj);
	friend void spellCheck(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size);
};

//!<------ Seat class to be inluded INSIDE Plane class ------>!
class Seat : public Passenger {
	bool empty = true;

	friend class Plane;
};

//!<------ Plane class with all planes data------>!
class Plane {
	static int totalIndex;
	int index = 0;
	string manufacturer;
	string destination;
	int flight;
	Seat seats[13][6];
	string date;
	int time_h;
	int time_m;
	friend class Passenger;
public:
//!<------ Plane class constructors to store passenger data ------>!
	Plane() :index(0), flight(0) {};
	Plane(string manufacturer, string destination, int flight, string date, int time_h, int time_m)
	{
		this->manufacturer = manufacturer;
		this->destination = destination;
		this->flight = flight;
		this->date = date;
		this->time_h = time_h;
		this->time_m = time_m;
		index = totalIndex;
		totalIndex++;
	}

//!<------ Plane class function that reads plane data from .txt file ------>!	
	void getData(string manufacturer, string destination, int flight, string date1, string date2, string date3, int time_h, int time_m)
	{
		this->manufacturer = manufacturer;
		this->destination = destination;
		this->flight = flight;
		this->date = date1 + ' ' + date2 + ' ' + date3;
		this->time_h = time_h;
		this->time_m = time_m;
	}

	//!<------ Passenger class functions to return passenger data ------>!
	int viewIndex()
	{
		return index;
	}
	int viewFlight()
	{
		return flight;
	}
	string viewDestination()
	{
		return destination;
	}
	string viewMan()
	{
		return manufacturer;
	}
	string viewDate()
	{
		return date;
	}
	int viewTime()
	{
		return time_h;
	}
	int viewHours()
	{
		return time_h;
	}
	int viewMinutes()
	{
		return time_m;
	}

//!<------ Plane class functions that check if seat is empty ------>!
	bool checkSeat(int i, int j)
	{
		return seats[i][j].empty;
	}

//!<------ Plane class functions that handles the booking ------>!
	void reserveSeat(Passenger &P)
	{
		int row, col;
		bool check = false;
		while (check == false)
		{
			cin >> row >> col;
			cin.ignore();
			if (seats[row][col].empty == true)
			{
				check = true;
				P.seat_row = row;
				P.seat_col = col;
				seats[row][col].empty = false;
				seats[row][col].id = P.id;
				seats[row][col].destination = P.destination;
				seats[row][col].email = P.email;
				seats[row][col].flight = P.flight;
				seats[row][col].name = P.name;
				seats[row][col].ticketType = P.ticketType;
				seats[row][col].seat_row = P.seat_row;
				seats[row][col].seat_col = P.seat_col;
			}
			else {
				cout << "Error!" << endl;
			}
		}
		
	}
	void emptySeat(Passenger &P)
	{
		int row, col;
		row = P.seat_row; col = P.seat_col;
		seats[row][col].empty = true;
		seats[row][col].id = "NULL";
		seats[row][col].destination = "NULL";
		seats[row][col].email = "NULL";
		seats[row][col].flight = NULL;
		seats[row][col].name = "NULL";
		seats[row][col].ticketType = "NULL";
		seats[row][col].seat_row = NULL;
		seats[row][col].seat_col = NULL;
	}
	void seatingPlan()
	{
		cout << "Row no." << setw(15) << "Col 0" << setw(15) << "Col 1" << setw(15) << "Col 2" << setw(15) << "Col 3" << setw(15) << "Col 4" << setw(15) << "Col 5" << endl;
		for (int i = 0; i<13; i++)
		{
			if (i == 2 || i == 7) {
				cout << endl;
			}

			if (i<10)
			{
				cout << "Row " << 0 << i;
			}
			else {
				cout << "Row " << i;
			}

			for (int j = 0; j<6; j++)
			{
				if (seats[i][j].empty == true)
				{
					cout << setw(15) << '*';
				}
				else {
					cout << setw(15) << 'X';
				}
			}
			cout << endl;
		}
	}
	void seatingPlanByTicket(Passenger &P)
	{
		if (P.ticketType == "FIRST")										// Displaying the seating plan for selected class
		{
			cout << "Row no." << setw(15) << "Col 0" << setw(15) << "Col 1" << setw(15) << "Col 2" << setw(15) << "Col 3" << setw(15) << "Col 4" << setw(15) << "Col 5" << endl;
			for (int i = 0; i<2; i++)
			{
				cout << "Row " << i;
				for (int j = 0; j<6; j++)
				{
					if (seats[i][j].empty == true)
					{
						cout << setw(15) << '*';
					}
					else {
						cout << setw(15) << 'X';
					}
				}
				cout << endl;
			}
		}
		else if (P.ticketType == "BUSINESS") {
			cout << "Row no." << setw(15) << "Col 0" << setw(15) << "Col 1" << setw(15) << "Col 2" << setw(15) << "Col 3" << setw(15) << "Col 4" << setw(15) << "Col 5" << endl;
			for (int i = 3; i<7; i++)
			{
				cout << "Row " << i;
				for (int j = 0; j<6; j++)
				{
					if (seats[i][j].empty == true)
					{
						cout << setw(15) << '*';
					}
					else {
						cout << setw(15) << 'X';
					}
				}
				cout << endl;
			}
		}
		else if (P.ticketType == "ECONOMY") {
			cout << "Row no." << setw(15) << "Col 0" << setw(15) << "Col 1" << setw(15) << "Col 2" << setw(15) << "Col 3" << setw(15) << "Col 4" << setw(15) << "Col 5" << endl;
			for (int i = 8; i<13; i++)
			{
				if (i<10)
				{
					cout << "Row " << 0 << i;
				}
				else {
					cout << "Row " << i;
				}
				for (int j = 0; j<6; j++)
				{
					if (seats[i][j].empty == true)
					{
						cout << setw(15) << '*';
					}
					else {
						cout << setw(15) << 'X';
					}
				}
				cout << endl;
			}
		}
	}
	void notifyPass(int row, int col)
	{
		this->seats[row][col].email;
		// Code to send email to passenger.
	}
	void listPass()
	{
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (checkSeat(i, j) == false)
				{
					this->seats[i][j].printFullData();
					cout << endl;
				}
			}
		}
	}
	void assignSeat(Passenger &P)
	{
		int row, col;
		row = P.seat_row;
		col = P.seat_col;
		P.seat_row = row;
		P.seat_col = col;
		this->seats[row][col].empty = false;
		this->seats[row][col].id = P.id;
		this->seats[row][col].destination = P.destination;
		this->seats[row][col].email = P.email;
		this->seats[row][col].flight = P.flight;
		this->seats[row][col].name = P.name;
		this->seats[row][col].ticketType = P.ticketType;
		this->seats[row][col].seat_row = P.seat_row;
		this->seats[row][col].seat_col = P.seat_col;
	}


	friend ostream& operator << (ostream& out, const Plane& obj);
	friend void spellCheck(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size);
}; int Plane::totalIndex = 0;