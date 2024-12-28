/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu
	
	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	cout << "****************************************************"
		<< endl << "                HIKING IN THE US" << endl
		<< "****************************************************"
		<< "\n\n\t 1. Browse by location"
		<< "\n\t 2. Browse by duration"
		<< "\n\t 3. Browse by difficulty"
		<< "\n\t 4. Browse by price"
		<< "\n\t 5. Make a reservation"
		<< "\n\t 6. View reservation"
		<< "\n\t 7. Cancel reservation"
		<< "\n\t 8. Exit\n\n";
}

void processReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "Please make a selection: ";
	int selection = 0;
	cin >> selection;
	cout << endl;

	while (selection != 8)
	{
		if (selection == 1) chooseByLocation(hikeList,
			memberList, reservedList);
		else if (selection == 2) chooseByDuration(hikeList,
			memberList, reservedList);
		else if (selection == 3) chooseByDifficulty(hikeList,
			memberList, reservedList);
		else if (selection == 4) chooseByPrice(hikeList,
			memberList, reservedList);
		else if (selection == 5) makeReservation(hikeList,
			memberList, reservedList);
		else if (selection == 6) viewReservation(hikeList,
			memberList, reservedList);
		else if (selection == 7) cancelReservation(hikeList,
			memberList, reservedList);

		system("Pause");
		cout << endl;
		displayMenu();
		cout << "Please make a selection: ";
		cin >> selection;
		cout << endl;
	}

	cout << "Thank you for visiting!" << endl;
}

void chooseByLocation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	hikeList.printAllLocations();

	cout << "\nChoose a location: ";
	string location;
	cin >> location;
	cout << endl;

	hikeList.printByLocation(location);
	askToReserve(hikeList, memberList, reservedList);
}

void chooseByDuration(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "\t(days)\n";
	hikeList.printByDuration();

	cout << "\nHow many days are you considering? ";
	int days = 0;
	cin >> days;

	hikeList.printByDuration(days);
	cout << endl;
	askToReserve(hikeList, memberList, reservedList);
}

void chooseByDifficulty(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "Choose a difficulty level: \n"
		<< "\n\te. easy"
		<< "\n\tm. moderate"
		<< "\n\ts. strenuous\n"
		<< "\nYour choice: ";
	char difficulty = 'e';
	cin >> difficulty;

	cout << "\n\t(difficulty level)\n";
	hikeList.printByDifficulty(difficulty);
	cout << endl;
	askToReserve(hikeList, memberList, reservedList);
}

void chooseByPrice(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	hikeList.printByPrice();
	cout << endl;
	askToReserve(hikeList, memberList, reservedList);
}

int askIfMember(MemberList& memberList)
{
	cout << "Are you a member? (y/n) ";
	char ifMember = 'n';
	cin >> ifMember;

	if (ifMember == 'y')
	{
		cout << "\nWhat is your member ID number? ";
		int id = 0;
		cin >> id;

		cout << "\nWhat is your last name? ";
		string lastName;
		cin >> lastName;
		cout << endl;

		memberList.printMember(id, lastName);
		cout << endl;

		return id;
	}
	else
	{
		return addNewMember(memberList);
	}
}

int addNewMember(MemberList& memberList)
{
	cout << "\n\tLet's add you to the member list!\n"
		<< "\t\tWhat is your first name? ";
	string firstName;
	cin >> firstName;

	cout << "\t\tWhat is your last name? ";
	string lastName;
	cin >> lastName;

	memberList.addMember(firstName, lastName);
	int memberID = memberList.getLastID();

	cout << "\n\tWelcome to the club!"
		<< "\n\t\tYour member ID number is: "
		<< memberID << "\n\n";

	return memberID;
}

void makeReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	int id = askIfMember(memberList);

	cout << "Which hike would you want to reserve (hike name)? ";
	string hikeName;
	cin >> hikeName;
	cout << endl;

	hikeList.printByHikeName(hikeName);

	int points = memberList.getPoints(id);
	double originalPrice = hikeList.getPrice(hikeName);

	if (points != 0)
	{
		cout << "\n\n\tDiscounted price using points: $"
			<< fixed << setprecision(2)
			<< (originalPrice - (points * 1 / 100));
	}

	cout << "\n\n\tBefore proceeding, please make a note "
		<< "of your reservation number.\n"
		<< "\t  Reservation #: "
		<< reservedList.addReservation(id, hikeName)
		<< "\n\n( *** Will continue to scheduling and payment."
		<< " *** )\n\n";
}

void viewReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "Enter reservation #: ";
	int reservedNumber = 0;
	cin >> reservedNumber;
	cout << endl;

	reservedList.printReservation(reservedNumber, hikeList,
		memberList);
	cout << endl;
}

void cancelReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "Enter reservation #: ";
	int reservedNumber = 0;
	cin >> reservedNumber;
	cout << endl;

	reservedList.printReservation(reservedNumber, hikeList,
		memberList);

	cout << "\nAre you sure you want to "
		<< "cancel this reservation? (y/n) ";
	char confirmRequest = 'n';
	cin >> confirmRequest;
	cout << endl;

	if (confirmRequest == 'y')
	{
		reservedList.cancelReservation(reservedNumber);
		cout << "Reservation #" << reservedNumber 
			<< " has been canceled.\n\n";
	}
}

void askToReserve(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList)
{
	cout << "Would you like to make a reservation? (y/n) ";
	char answer = 'n';
	cin >> answer;
	cout << endl;

	if (answer == 'y')
	{
		makeReservation(hikeList, memberList, reservedList);
	}
}

