/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Member.h"

#include <iomanip>
#include <iostream>

using namespace std;

Member::Member(const std::string& newFirstName,
	const std::string& newLastName)
{
	id = 0;
	firstName = newFirstName;
	lastName = newLastName;
	points = 0;
}

void Member::addPoints(int newPoints)
{
	points += newPoints;
}

void Member::setID(int newID)
{
	id = newID;
}

int Member::getID() const
{
	return id;
}

std::string Member::getLastName() const
{
	return lastName;
}

int Member::getPoints() const
{
	return points;
}

bool Member::operator<(const Member& otherMember) const
{
	return (id < otherMember.id);
}

void Member::printMember() const
{
	cout << "\t" << lastName << ", " << firstName << endl
		<< "\t" << "Points available: " << points << endl;
}

Member::~Member() {}
