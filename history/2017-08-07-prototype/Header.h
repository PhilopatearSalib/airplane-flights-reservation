#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Passenger {
	int id;
	string name;
	int flight;
	string ticketType;
	string destination;
	int seat_row;
	int seat_col;
	friend class Plane;
	friend class Seat;

public:

	void setID()
	{
		int id;
		cin >> id;
		cin.ignore();
		this->id = id;
	}
	void setName()
	{
		string Name;
		getline(cin, Name);
		this->name = Name;
	}
	void setTicketType()
	{
		string ticket;
		getline(cin, ticket);
		this->ticketType = ticket;
	}
	void setDestination()
	{
		string dest;
		getline(cin, dest);
		this->destination = dest;
	}
	void setFlight()
	{
		int flight;
		cin >> flight;
		cin.ignore();
		this->flight = flight;
	}

	int viewID()
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
	void view()
	{
		cout << seat_row << ' ' << seat_col << endl;
	}
	friend ostream& operator << (ostream& out, const Passenger& obj);

};

class Seat : public Passenger {
	bool empty = true;
	int row;
	int col;
	friend class Plane;
};

class Plane {
	static int totalIndex;
	int index = 0;
	string manufacturer;
	string destination;
	int flight;
	Seat seats[13][6];
	friend class Passenger;
public:
	Plane() :index(0), flight(0) {};
	Plane(string manufacturer, string destination, int flight)
	{
		this->manufacturer = manufacturer;
		this->destination = destination;
		this->flight = flight;
		index = totalIndex;
		totalIndex++;
	}

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

	bool checkSeat(int i, int j)
	{
		return seats[i][j].empty;
	}

	void getData(string man, string dest, int flight)
	{
		
		this->manufacturer = man;
		this->destination = dest;
		this->flight = flight;
	}
	void reserveSeat(Passenger &P)
	{
		int row, col;
		cin >> row >> col;
		cin.ignore();
		seats[row][col].empty = false;
		seats[row][col].id = P.id;
		P.seat_row = row;
		P.seat_col = col;
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
	void seatingPlanByTicket(Passenger P)
	{
		if (P.ticketType == "First")										// Displaying the seating plan for selected class
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
		else if (P.ticketType == "Business") {
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
		else if (P.ticketType == "Economy") {
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
	void man()
	{
		cout << manufacturer << endl;
	}
}; int Plane::totalIndex = 0;