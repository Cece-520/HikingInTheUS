/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu
	
	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <string>
#include <set>

const int ID = 111;

class MemberList
{
public:
	MemberList() : memberList(new std::set<Member>) {}

	void addMember(const std::string& newFirstName,
		const std::string& newLastName);
	void addMember(const std::string& newFirstName,
		const std::string& newLastName, int newPoints);

	int getLastID() const;
	int getPoints(int searchedID) const;

	void printMember(int searchedID,
		const std::string& searchedLastName) const;

	void clearList();
	~MemberList();
private:
	std::set<Member>* memberList;
};
#endif