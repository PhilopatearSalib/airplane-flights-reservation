#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

bool checkForEmptySeats(Plane arr[], bool emptySeat)
{
	int l = 0, i = 0, j = 0;
	while (emptySeat == false)
	{
		if (arr[l].checkSeat(i, j) == true)
		{
			emptySeat = true;
		}
		else {
			emptySeat = false;
		}
		if (j == 6)
		{
			i++; j = 0;
		}
		if (i == 12)
		{
			l++; i = 0; j = 0;
		}
		if (l == 6)
		{
			break;
		}
	}
	return emptySeat;
}

ostream& operator << (ostream& out, const Passenger& obj)
{
	out << obj.id << ' ';
	out << obj.name << ' ';
	out << obj.destination << ' ';
	out << obj.flight << ' ';
	out << obj.ticketType << " row:";
	out << obj.seat_row << " col:";
	out << obj.seat_col;
	return out;
}

int main()
{
	ifstream inFile("Planes.txt");
	Plane* ptr = new Plane[40];
	for (int i = 0; i < 40; i++)
	{
		string manufacturer, destination; int flight;
		inFile >> manufacturer >> destination >> flight;
		ptr[i].getData(manufacturer, destination, flight);
	}
	inFile.close();

	bool emptySeat;
	int index;
	//while (checkForEmptySeats(ptr, emptySeat) == true)
	{
		Passenger* temp = new Passenger;
		cout << "Good Morning! Please enter your ID and Name" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setID();
		temp->setName();
		cout << endl;

		cout << "Please Enter Your Destination" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setDestination();
		cout << endl;

		cout << "Flights going to ";;
		temp->printDestination();
		cout << " are :: ";
		for (int i = 0; i < 40; i++)
		{
			if (ptr[i].viewDestination() == temp->viewDestination())
			{
				cout << ptr[i].viewFlight() << "  ";
			}
		}
		cout << endl;

		cout << "Please Choose Your Flight :: ";
		temp->setFlight();
		cout << "---------------------------------------------" << endl;
		cout << endl;

		for (int i = 0; i < 40; i++)
		{
			if (ptr[i].viewFlight() == temp->viewFlight())
			{
				index = ptr[i].viewIndex();
			}
		}
		cout << "Please Choose Your Ticket Type (First, Business or Economy) :: ";
		temp->setTicketType();
		cout << "---------------------------------------------" << endl;
		ptr[index].seatingPlanByTicket((*temp));

		cout << "Please Choose Your Seat By Entering The Row Number Followed By Column Number :: ";
		ptr[index].reserveSeat((*temp));
		temp->view();
		cout << "Your Seat Has Been Reserved";
		cout << endl;
		ptr[index].seatingPlan();
		cout << "---------------------------------------------" << endl;
		cout << "Thank You. Have a Great Day!" << endl;
		cout << "---------------------------------------------" << endl;

		ofstream outFile("Passengers.txt");
		outFile << (*temp);
		outFile.close();
		delete temp;
	}
}