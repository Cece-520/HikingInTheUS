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
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"

using namespace std;

int main()
{
	MemberList myMember;
	HikeList myHike;
	Reservations myReserved;

	getMemberData(myMember);
	getHikeData(myHike);
	getReservationData(myReserved);

	displayMenu();
	processReservation(myHike, myMember, myReserved);
	return 0;
}