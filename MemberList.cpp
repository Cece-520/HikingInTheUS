/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "MemberList.h"
#include "Member.h"

#include <algorithm>
#include <iostream>

using namespace std;

void MemberList::addMember(const string& newFirstName,
	const string& newLastName)
{
	int newID = ID;
	Member newMember(newFirstName, newLastName);

	if (memberList->size() == 0)
	{
		newMember.setID(newID);
	}
	else
	{
		Member last = *(memberList->rbegin());
		newID = last.getID() + 1;
		newMember.setID(newID);
	}

	memberList->insert(newMember);
}

void MemberList::addMember(const string& newFirstName,
	const string& newLastName, int newPoints)
{
	int newID = ID;
	Member newMember(newFirstName, newLastName);
	newMember.addPoints(newPoints);

	if (memberList->size() == 0)
	{
		newMember.setID(newID);
	}
	else
	{
		Member last = *(memberList->rbegin());
		newID = last.getID() + 1;
		newMember.setID(newID);
	}

	memberList->insert(newMember);
}

int MemberList::getLastID() const
{
	return (memberList->rbegin()->getID());
}

int MemberList::getPoints(int searchedID) const
{
	auto iterMember = find_if(memberList->begin(),
		memberList->end(), [&searchedID](Member member)
		{ return (member.getID() == searchedID); });
	return iterMember->getPoints();
}

void MemberList::printMember(int searchedID,
	const string& searchedLastName) const
{
	auto iterMember = find_if(memberList->begin(),
		memberList->end(), [&searchedID](Member member)
		{ return member.getID() == searchedID; });

	if (iterMember->getLastName() == searchedLastName)
	{
		iterMember->printMember();
		cout << "\t" << "Membership # "
			<< iterMember->getID() << endl;
	}
}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	delete memberList;
	memberList = nullptr;
}