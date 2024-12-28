/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();
void processReservation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservedList);
void chooseByLocation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservedList);
void chooseByDuration(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
void chooseByDifficulty(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
void chooseByPrice(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
int askIfMember(MemberList& memberList);
int addNewMember(MemberList& memberList);
void makeReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
void viewReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
void cancelReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);
void askToReserve(HikeList& hikeList,
	MemberList& memberList, Reservations& reservedList);

#endif