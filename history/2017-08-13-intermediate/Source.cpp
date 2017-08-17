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
	out << obj.email << ' ';
	out << obj.destination << ' ';
	out << obj.flight << ' ';
	out << obj.ticketType << ' ';
	out << obj.seat_row << ' ';
	out << obj.seat_col << endl;
	return out;
}
ostream& operator << (ostream& out, const Plane& obj)
{
	out << obj.manufacturer << ' ';
	out << obj.destination << ' ';
	out << obj.flight << endl;
	return out;
}

Passenger* addNewPassenger(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	Passenger *newArr = new Passenger[passenger_size + 1];
	for (int i = 0; i < passenger_size; i++)
	{
		newArr[i] = arr[i];
	}

		int index;
		Passenger* temp = new Passenger;
		cout << "Please Enter The ID" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setID();
		cout << endl;
		cout << "Please Enter The Name" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setName();
		cout << endl;
		cout << "Please Enter The Email" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setEmail();
		cout << endl;

		cout << "Please Enter The Destination" << endl;
		cout << "---------------------------------------------" << endl;
		temp->setDestination();
		cout << endl;

		cout << "Flights going to ";
		temp->printDestination();
		cout << " are :: ";
		for (int i = 0; i < plane_size; i++)
		{
			if (ptr[i].viewDestination() == temp->viewDestination())
			{
				cout << ptr[i].viewFlight() << "  ";
			}
		}
		cout << endl;

		cout << "Please Choose The Flight :: ";
		temp->setFlight();
		cout << "---------------------------------------------" << endl;
		cout << endl;

		for (int i = 0; i < plane_size; i++)
		{
			if (ptr[i].viewFlight() == temp->viewFlight())
			{
				index = ptr[i].viewIndex();
			}
		}
		cout << "Please Choose The Ticket Type (First, Business or Economy) :: ";
		temp->setTicketType();
		cout << "---------------------------------------------" << endl;
		ptr[index].seatingPlanByTicket((*temp));

		cout << "Please Choose The Seat By Entering The Row Number Followed By Column Number :: ";
		ptr[index].reserveSeat((*temp));
		cout << "The Seat Has Been Reserved";
		cout << endl;
		ptr[index].seatingPlan();
		cout << "---------------------------------------------" << endl;
		cout << "Thank You. The booking is now complete!" << endl;
		cout << "---------------------------------------------" << endl;

	newArr[passenger_size] = *temp;
	passenger_size++;
	delete[]arr;
	delete temp;
	return newArr;
}
void editPassenger(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	int index;
	int pass_index;
	string ID;
	Passenger* temp;
	cout << "Enter The ID Of The Passenger You Want To Edit :: ";
	getline(cin, ID);
	for (int i = 0; i < passenger_size; i++)
	{
		if (ID == arr[i].viewID())
		{
			pass_index = i;
			temp = &arr[i];
			cout << "Enter new ID :: ";
			temp->setID();
			cout << endl;
			cout << "Enter new Name :: ";
			temp->setName();
			cout << endl;
			cout << "Enter new Email :: ";
			temp->setEmail();
			cout << endl;
			cout << "Enter new Destination :: ";
			temp->setDestination();
			cout << endl;
			cout << "Flights going to ";
			temp->printDestination();
			cout << " are :: ";
			for (int i = 0; i < plane_size; i++)
			{
				if (ptr[i].viewDestination() == temp->viewDestination())
				{
					cout << ptr[i].viewFlight() << "  ";
				}
			}
			cout << endl;
			cout << "Choose Flight :: ";
			temp->setFlight();
			cout << endl;
			for (int i = 0; i < plane_size; i++)
			{
				if (ptr[i].viewFlight() == temp->viewFlight())
				{
					index = ptr[i].viewIndex();
				}
			}
			ptr[index].emptySeat((*temp));
			cout << "Choose Ticket Type :: ";
			temp->setTicketType();
			cout << endl;
			ptr[index].seatingPlanByTicket((*temp));

			cout << "Please Choose The Seat By Entering The Row Number Followed By Column Number :: ";
			ptr[index].reserveSeat((*temp));
			cout << "The Seat Has Been Reserved";
			cout << endl;
			ptr[index].seatingPlan();
			cout << "Thank You. The booking is now complete!" << endl << endl;
			arr[pass_index] = (*temp);
		}
	}
	

}
Passenger* cancelReservation(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	int index;
	int pass_index;
	string ID;
	Passenger* temp;
	cout << "Enter The ID Of The Passenger You Want To Cancel Their Reservation :: ";
	getline(cin, ID);
	for (int i = 0; i < passenger_size; i++)
	{
		if (ID == arr[i].viewID())
		{
			pass_index = i;
			temp = &arr[i];
			cout << "The Passenger with ID :: " << temp->viewID() << " is :: " << temp->viewName() << " And Going To :: " << temp->viewDestination() << endl;
			cout << "Are You Sure You Want To Cancel The Reservation For " << temp->viewName() << " ?  (Yes/No)" << endl;
			string choice;
			for (int i = 0; i < plane_size; i++)
			{
				if (temp->viewFlight() == ptr[i].viewFlight())
				{
					index = i;
				}
			}

			if (choice == "Yes" || choice == "yes" || choice == "YES")
			{
				for (int i = pass_index; i<passenger_size - 1; i++) {
					arr[i] = arr[i + 1];
				}
				passenger_size--;
				ptr[index].emptySeat((*temp));
				cout << "Reservation Is Deleted" << endl << endl;
				return arr;
			}
			else {
				cout << "Error!" << endl;
				return 0;
			}
		}
	}
	
}
Plane* addNewPlane(Plane *ptr, int &plane_size)
{
	Plane *newArr = new Plane[plane_size + 1];
	for (int i = 0; i < plane_size; i++)
	{
		newArr[i] = ptr[i];
	}
	int index;
	Plane* temp = new Plane;
	string man, dest; int flight;
	cout << "Enter The Manufacturer Of The Plane" << endl;
	getline(cin, man);
	cout << "Enter The Destination Of The Plane" << endl;
	getline(cin, dest);
	cout << "Enter The Flight Numbe Of The Plane" << endl;
	cin >> flight;
	cin.ignore();
	temp->getData(man, dest, flight);
	newArr[plane_size] = *temp;
	plane_size++;
	delete[]ptr;
	delete temp;
	return newArr;

}
void editPlane(Plane *ptr, const int plane_size)
{
	int flight;
	int plane_index;
	cout << "Ente The Flight Number" << endl;
	cin >> flight;
	cin.ignore();
	Plane* temp;
	for (int i = 0; i < plane_size; i++)
	{
		if (flight == ptr[i].viewFlight())
		{
			plane_index = i;
			temp = &ptr[i];
			string man, dest; int newFlight;
			cout << "Enter The Manufacturer Of The Plane" << endl;
			getline(cin, man);
			cout << "Enter The Destination Of The Plane" << endl;
			getline(cin, dest);
			cout << "Enter The Flight Numbe Of The Plane" << endl;
			cin >> newFlight;
			cin.ignore();
			temp->getData(man, dest, newFlight);
			cout << "Flight Has Been Updated" << endl;
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (temp->checkSeat(i, j) == false)
					{
						temp->notifyPass(i, j);
					}
				}
			}
			delete temp;
			ptr[plane_index] = (*temp);
		}

	}
	

}
Plane* cancelFlight(Plane *ptr, int &plane_size)
{
	int index;
	int plane_index;
	int flight;
	Plane* temp;
	cout << "Enter The Flight Number Of The Plane :: ";
	cin >> flight;
	cin.ignore();
	for (int i = 0; i < plane_size; i++)
	{
		if (flight == ptr[i].viewFlight())
		{
			plane_index = i;
			temp = &ptr[i];
			cout << "The Flight with number :: " << temp->viewFlight() << " Going To :: " << temp->viewDestination() << endl;
			cout << "Are You Sure You Want To Cancel The Reservation For " << temp->viewFlight() << " ?  (Yes/No)" << endl;
			string choice;
			if (choice == "Yes" || choice == "yes" || choice == "YES")
			{
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (ptr[plane_index].checkSeat(i, j) == false)
						{
							temp->notifyPass(i, j);
						}
					}
				}
				for (int i = plane_index; i<plane_size - 1; i++) {
					ptr[i] = ptr[i + 1];
				}
				plane_size--;
				cout << "Reservation Is Deleted" << endl << endl;
				return ptr;
			}
			else {
				cout << "Error!" << endl;
				return 0;
			}
		}
	}
	
}

void main()
{
	// Indexing the Planes and Passengers into Arrays.
	// Indexing the passenger database inside an array of passengers.
	ifstream inPassengers("Passengers.txt", ios::app);
	int passenger_size = 0;
	string line;
	while (getline(inPassengers, line))
	{
		++passenger_size;
	}
	Passenger* PassArr = new Passenger[passenger_size];
	ifstream inPassengers2("Passengers.txt", ios::app);
	for (int i = 0; i <passenger_size; i++)
	{
		string id{}, fname{}, lname{}, email{}, destination{}, ticket{}; int flight{}, row{}, col{};
		inPassengers2 >> id >> fname >> lname >> email >> destination >> flight >> ticket >> row >> col;
		//cout << id << ' ' << fname << ' ' << lname << ' ' << email << ' ' << destination << ' ' << flight << ' ' << ticket << ' ' << row << ' ' << col << endl;
		PassArr[i].getData(id, fname, lname, email, destination, flight, ticket, row, col);
	}
	inPassengers.close();
	inPassengers2.close();

	// Indexing the plane database inside an array of planes.
	ifstream inPlanes("Planes.txt");
	int plane_size = 0;
	while (getline(inPlanes, line))
	{
		++plane_size;
	}
	ifstream inPlanes2("Planes.txt");
	Plane* PlaneArr = new Plane[plane_size];
	for (int i = 0; i <plane_size; i++)
	{
		string manufacturer{}, destination{}; int flight{};
		inPlanes2 >> manufacturer >> destination >> flight;
		//cout << manufacturer << ' ' << destination << ' ' << flight << endl;
		PlaneArr[i].getData(manufacturer, destination, flight);
	}
	inPlanes.close();
	inPlanes2.close();

	// !<---------- Main Program ---------->!
	bool exit = false;
	cout << "Good Morning! What do you want to do ?" << endl;
label_main_menu:
	while (exit == false)
	{
		cout << "--------------------------------------" << endl;
		cout << "1- Register new Passenger" << endl << endl;
		cout << "2- Edit existing Passenger data" << endl << endl;
		cout << "3- Cancel reservation of existing Passenger" << endl << endl;
		cout << "4- Register New Plane " << endl << endl;
		cout << "5- Edit Existing Plane Data" << endl << endl;
		cout << "6- Cancel Flight" << endl << endl;
		cout << "7- Exit Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Please enter your choice :: ";
		int choice, leave;
		cin >> choice;
		cin.ignore();
		cout << "--------------------------------------" << endl << endl;
		switch (choice)
		{
		case 1:
			PassArr = addNewPassenger(PlaneArr, PassArr, passenger_size, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
			break;

		case 2:
			editPassenger(PlaneArr, PassArr, passenger_size, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
		case 3:
			PassArr = cancelReservation(PlaneArr, PassArr, passenger_size, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
			break;
		case 4:
			PlaneArr = addNewPlane(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
			break;
		case 5:
			editPlane(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
			break;
		case 6:
			PlaneArr = cancelFlight(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else {
				goto label_exit;
			}
			break;
label_exit:
		case 7:
			cout << "--------------------------------------" << endl;
			cout << "Thank you. Program will terminate now" << endl;
			cout << "--------------------------------------" << endl << endl;
			ofstream outPass("Passengers.txt");
			for (int i = 0; i < passenger_size; i++)
			{
				outPass << PassArr[i];
			}
			outPass.close();
			ofstream outPlane("Planes.txt");
			for (int i = 0; i < plane_size; i++)
			{
				outPass << PlaneArr[i];
			}
			outPlane.close();
			delete[]PassArr;
			delete[]PlaneArr;
			exit = true;
			break;
		}
	}


}