#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

ostream& operator << (ostream& out, const Passenger& obj)
{
	out << obj.id << "  ";
	out << obj.name << "  ";
	out << obj.email << "  ";
	out << obj.destination << "  ";
	out << obj.flight << "  ";
	out << obj.ticketType << "  ";
	out << obj.seat_row << "  ";
	out << obj.seat_col << endl;
	return out;
}
ostream& operator << (ostream& out, const Plane& obj)
{
	out << obj.manufacturer << "  ";
	out << obj.destination << "  ";
	out << obj.flight << "  ";
	out << obj.date << "  ";
	out << obj.time_h << "  ";
	out << obj.time_m << "  " << endl;
	return out;
}

void autoAssign(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	for (int i = 0; i < passenger_size; i++)
	{
		for (int j = 0; j < plane_size; j++)
		{
			if (ptr[j].viewFlight() == arr[i].viewFlight())
			{
				ptr[j].assignSeat(arr[i]);
			}
		}
	}
}
void spellCheck(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	for (int i = 0; i < plane_size; i++)
	{
		for (int j = 0; j < ptr[i].date.size(); ++j)
		{
			ptr[i].date[j] = toupper(ptr[i].date[j]);
		}

		for (int j = 0; j < ptr[i].manufacturer.size(); ++j)
		{
			ptr[i].manufacturer[j] = toupper(ptr[i].manufacturer[j]);
		}

		for (int j = 0; j < ptr[i].destination.size(); j++)
		{
			ptr[i].destination[j] = toupper(ptr[i].destination[j]);
		}
	}

	for (int i = 0; i < passenger_size; i++)
	{
		for (int j = 0; j < arr[i].id.size(); j++)
		{
			arr[i].id[j] = toupper(arr[i].id[j]);
		}
		for (int j = 0; j < arr[i].name.size(); j++)
		{
			arr[i].name[j] = toupper(arr[i].name[j]);
		}
		for (int j = 0; j < arr[i].email.size(); j++)
		{
			arr[i].email[j] = toupper(arr[i].email[j]);
		}
		for (int j = 0; j < arr[i].destination.size(); j++)
		{
			arr[i].destination[j] = toupper(arr[i].destination[j]);
		}
		for (int j = 0; j < arr[i].ticketType.size(); j++)
		{
			arr[i].ticketType[j] = toupper(arr[i].ticketType[j]);
		}
	}
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
		cout << " are :: " << endl;
		for (int i = 0; i < plane_size; i++)
		{
			if (ptr[i].viewDestination() == temp->viewDestination())
			{
				cout << ptr[i].viewFlight() << "  " << ptr[i].viewDate() << " " << ptr[i].viewHours() << ':' << ptr[i].viewMinutes() << endl;
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
				index = i;
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
	bool match = false;
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
			match = true;
			pass_index = i;
			temp = &arr[i];
			cout << temp->viewID() << ' ' << temp->viewName() << ' ' << temp->viewEmail() << ' ' << temp->viewDestination() << ' ' << temp->viewFlight() << ' ' << temp->viewTicketType() << ' ' << temp->viewSeatRow() << ' ' << temp->viewSeatCol() << endl << endl;
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
			cout << " are :: " << endl;
			for (int i = 0; i < plane_size; i++)
			{
				if (ptr[i].viewDestination() == temp->viewDestination())
				{
					cout << ptr[i].viewFlight() << "  " << ptr[i].viewDate() << " " << ptr[i].viewHours() << ':' << ptr[i].viewMinutes() << endl;
				}
			}
			cout << endl;
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
	if (match == false)
	{
		cout << "Error Code 82" << endl << endl;
	}

}
void searchPassenger(Passenger* arr, int &passenger_size)
{
	bool match = false;
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
			match = true;
			pass_index = i;
			temp = &arr[i];
			cout << temp->viewID() << ' ' << temp->viewName() << ' ' << temp->viewEmail() << ' ' << temp->viewDestination() << ' ' << temp->viewFlight() << ' ' << temp->viewTicketType() << ' ' << temp->viewSeatRow() << ' ' << temp->viewSeatCol() << endl << endl;
		}
	}
	if (match == false)
	{
		cout << "Error Code 82" << endl << endl;
	}
}
Passenger* cancelReservation(Plane *ptr, Passenger* arr, int &passenger_size, const int plane_size)
{
	bool match = false;
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
			match = true;
			pass_index = i;
			temp = &arr[i];
			for (int i = 0; i < plane_size; i++)
			{
				if (temp->viewFlight() == ptr[i].viewFlight())
				{
					index = i;
				}
			}
			cout << "The Passenger with ID :: " << temp->viewID() << " is :: " << temp->viewName() << " And Going To :: " << temp->viewDestination() << " On :: " << ptr[index].viewDate() << endl << endl;
			cout << "Are You Sure You Want To Cancel The Reservation For " << temp->viewName() << " ?  (Yes/No)" << endl;
			string choice;
			getline(cin, choice);
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
				cout << "Reservation Is Not Deleted" << endl;
				return 0;
			}
		}
	}
	if (match == false)
	{
		cout << "Error Code 82" << endl << endl;
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
	string man, dest, date1, date2, date3; int fl, th, tm;
	cout << "Enter The Manufacturer" << endl;
	getline(cin, man);
	cout << "Enter The Destination" << endl;
	getline(cin, dest);
	cout << "Enter The Flight Number" << endl;
	cin >> fl;
	cin.ignore();
	cout << "Enter The Date Of Departure (Day 18th Month)" << endl;
	cin >> date1 >> date2 >> date3;
	cout << "Enter The Time Of Departure" << endl;
	cin >> th;
	cin.ignore();
	cin >> tm;
	cin.ignore();
	temp->getData(man, dest, fl, date1, date2, date3, th, tm);
	newArr[plane_size] = *temp;
	cout << "New Flight " << newArr[plane_size].viewFlight() << " Going To " << newArr[plane_size].viewDestination() << " On " << newArr[plane_size].viewDate() << "  " << newArr[plane_size].viewHours() << ':' << newArr[plane_size].viewMinutes() << endl;
	cout << "--------------------------------------" << endl;
	plane_size++;
	delete[]ptr;
	delete temp;
	return newArr;
}
void editPlane(Plane *ptr, const int plane_size)
{
	bool match = false;
	int flight;
	int plane_index;
	cout << "Enter The Flight Number" << endl;
	cin >> flight;
	cin.ignore();
	Plane* temp;
	for (int i = 0; i < plane_size; i++)
	{
		if (flight == ptr[i].viewFlight())
		{
			match = true;
			plane_index = i;
			temp = &ptr[i];
			cout << temp->viewMan() << ' ' << temp->viewFlight() << ' ' << temp->viewDestination() << ' ' << temp->viewDate() << ' ' << temp->viewHours() << ':' << temp->viewMinutes() << endl << endl;
			string man, dest, date1, date2, date3; int fl, th, tm;
			cout << "Enter The Manufacturer" << endl;
			getline(cin, man);
			cout << "Enter The Destination" << endl;
			getline(cin, dest);
			cout << "Enter The Flight Number" << endl;
			cin >> fl;
			cin.ignore();
			cout << "Enter The Date Of Departure (Day 18th Month)" << endl;
			cin >> date1 >> date2 >> date3;
			cout << "Enter The Time Of Departure" << endl;
			cin >> th;
			cin.ignore();
			cin >> tm;
			cin.ignore();
			temp->getData(man, dest, fl, date1, date2, date3, th, tm);
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
			cout << endl;
			cout << "Boarding Passengers Are Notified" << endl;
			cout << "Flight Has Been Updated" << endl;
			ptr[plane_index] = (*temp);
			cout << ptr[plane_index].viewMan() << ' ' << ptr[plane_index].viewFlight() << ' ' << ptr[plane_index].viewDestination() << ' ' << ptr[plane_index].viewDate() << ' ' << ptr[plane_index].viewHours() << ':' << ptr[plane_index].viewMinutes() << endl << endl;
			//delete temp;
		}
	}
	if (match == false)
	{
		cout << "Error Code 84" << endl << endl;
	}

}
void listPassengers(Plane *ptr, const int plane_size)
{
	bool match = false;
	int flight;
	int plane_index;
	cout << "Enter The Flight Number" << endl;
	cin >> flight;
	cin.ignore();
	Plane* temp;
	for (int i = 0; i < plane_size; i++)
	{
		if (flight == ptr[i].viewFlight())
		{
			match = true;
			temp = &ptr[i];
			cout << temp->viewMan() << ' ' << temp->viewFlight() << ' ' << temp->viewDestination() << ' ' << temp->viewDate() << ' ' << temp->viewHours() << ':' << temp->viewMinutes() << endl << endl;
			temp->listPass();
		}
	}
	if (match == false)
	{
		cout << "Error Code 84" << endl << endl;
	}
}
void listAll(Passenger* arr, int &passenger_size)
{
	for(int i = 0; i < passenger_size;i++)
	{
		arr[i].printFullData();
		cout << endl;
	}
}
void searchPlane(Plane *ptr, const int plane_size)
{
	bool match = false;
	int flight;
	int plane_index;
	cout << "Enter The Flight Number" << endl;
	cin >> flight;
	cin.ignore();
	Plane* temp;
	for (int i = 0; i < plane_size; i++)
	{
		if (flight == ptr[i].viewFlight())
		{
			match = true;
			plane_index = i;
			temp = &ptr[i];
			cout << temp->viewMan() << ' ' << temp->viewFlight() << ' ' << temp->viewDestination() << ' ' << temp->viewDate() << ' ' << temp->viewHours() << ':' << temp->viewMinutes() << endl;
		}
	}
	if (match == false)
	{
		cout << "Error Code 84" << endl << endl;
	}
}
void searchInterval(Plane *ptr, const int plane_size)
{
	bool match = false;
	int th1, tm1, th2, tm2;
	cout << "From :: ";
	cin >> th1 >> tm1;
	cin.ignore();
	cout << " To :: ";
	cin >> th2 >> tm2;
	cin.ignore();

	for (int i = 0; i < plane_size; i++)
	{
		if (ptr[i].viewHours() >= th1 && (ptr[i].viewHours() < (th2+1)))
		{
			match = true;
			cout << ptr[i].viewFlight() << ' ' << ptr[i].viewDestination() << ' ' << ptr[i].viewHours() << ':' << ptr[i].viewMinutes() << endl;
		}
	}
	if (match == false)
	{
		cout << "Error Code 97!" << endl;
	}
}
Plane* cancelFlight(Plane *ptr, int &plane_size)
{
	bool match = false;
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
			match = true;
			plane_index = i;
			temp = &ptr[i];
			cout << "The Flight with number :: " << temp->viewFlight() << " Going To :: " << temp->viewDestination() << " On :: " << temp->viewDate() << endl;
			cout << "Are You Sure You Want To Cancel The Reservation For " << temp->viewFlight() << " ?  (Yes/No)" << endl;
			string choice;
			getline(cin, choice);
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
				cout << endl;
				cout << "Flight Is Deleted" << endl;
				cout << "Passengers Have Been Notified" << endl;
				return ptr;
			}
			else {
				cout << "Flight Is Not Deleted!" << endl;
				return 0;
			}
		}
	}
	if (match == false)
	{
		cout << "Error Code 84" << endl << endl;
	}
	
}



int main()
{
	// Indexing the Planes and Passengers into Arrays.
	// Indexing the plane database inside an array of planes.
	ifstream inPlanes("Planes.txt");
	int plane_size = 0;
	string line2;
	while (getline(inPlanes, line2))
	{
		++plane_size;
	}
	Plane* PlaneArr = new Plane[plane_size];
	ifstream inPlanes2("Planes.txt");
	for (int i = 0; i <plane_size; i++)
	{
		string manufacturer, destination, date1, date2, date3; int flight, time_h, time_m;
		inPlanes2 >> manufacturer >> destination >> flight >> date1 >> date2 >> date3 >> time_h >> time_m;
		PlaneArr[i].getData(manufacturer, destination, flight, date1, date2, date3, time_h, time_m);
	}
	inPlanes.close();
	inPlanes2.close();

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
		//PassArr[i].printDestination();
		//PassArr[i].printSeat();
	}
	inPassengers.close();
	inPassengers2.close();

	spellCheck(PlaneArr, PassArr, passenger_size, plane_size);
	autoAssign(PlaneArr, PassArr, passenger_size, plane_size);

	// !<---------- Main Program ---------->!
	bool exit = false;
	cout << "Good Morning! What do you want to do ?" << endl;

	while (exit == false)
	{ 
	label_main_menu:
		spellCheck(PlaneArr, PassArr, passenger_size, plane_size);
		cout << "--------------------------------------" << endl;
		cout << "1- Register New Passenger" << endl << endl;
		cout << "2- Edit Existing Passenger Data" << endl << endl;
		cout << "3- Search For An Existing Passenger data" << endl << endl;
		cout << "4- Cancel Reservation Of Existing Passenger" << endl << endl;
		cout << "5- Register New Flight" << endl << endl;
		cout << "6- Edit Existing Flight Data" << endl << endl;
		cout << "7- List Passengers Of An Existing Flight" << endl << endl;
		cout << "8- List All Passengers On All Flight" << endl << endl;
		cout << "9- Search For Flight Data" << endl << endl;
		cout << "10- Search For Flight During Time Interval" << endl << endl;
		cout << "11- Cancel Flight" << endl << endl;
		cout << "12- Exit Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Please enter your choice :: ";
		int choice = 0;
		int leave = 0;
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
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
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
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 3:
			searchPassenger(PassArr, passenger_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 4:
			PassArr = cancelReservation(PlaneArr, PassArr, passenger_size, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 5:
			PlaneArr = addNewPlane(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 6:
			editPlane(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 7:
			listPassengers(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 8:
			listAll(PassArr, passenger_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 9:
			searchPlane(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 10:
			searchInterval(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
		case 11:
			PlaneArr = cancelFlight(PlaneArr, plane_size);
			cout << "Press 0 To Exit Program Or 1 To Go Back To Main Menu :: ";
			cin >> leave;
			cin.ignore();
			if (leave == 1)
			{
				goto label_main_menu;
			}
			else if (leave == 0) {
				goto label_exit;
			}
			else {
				cout << "Error Code 71" << endl;
				goto label_main_menu;
			}
			break;
label_exit:
		case 12:
		{
			cout << "--------------------------------------" << endl;
			cout << "Thank you. Program will terminate now" << endl;
			cout << "--------------------------------------" << endl << endl;
			spellCheck(PlaneArr, PassArr, passenger_size, plane_size);
			ofstream outPass("Passengers.txt");
			for (int i = 0; i < passenger_size; i++)
			{
				outPass << PassArr[i];
			}
			outPass.close();
			ofstream outPlane("Planes.txt");
			for (int i = 0; i < plane_size; i++)
			{
				outPlane << PlaneArr[i];
			}
			outPlane.close();
			delete[]PassArr;
			delete[]PlaneArr;
			exit = true;
			break;
		}
		default:
			cout << "Error Code 60" << endl;
		}
	}
}