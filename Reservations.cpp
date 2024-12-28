/*
    Alpha Team

    Pham, Kayden
    Pham, Cecilia
    Luong, Nhu

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Reservations.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int newMemberID,
    const string& newHikeName)
{
    int newReservationNumber = RESERVATION_NUMBER;

    if (count == 0)
    {
        newReservationNumber = RESERVATION_NUMBER;
        first = new Node(newReservationNumber, newMemberID,
            newHikeName, nullptr, nullptr);
        last = first;
    }
    else
    {
        newReservationNumber = last->getReservationNumber() + 1;
        last = new Node(newReservationNumber, newMemberID,
            newHikeName, last, nullptr);
        last->getPrev()->setNext(last);
    }

    ++count;
    return newReservationNumber;
}

void Reservations::cancelReservation(int reservationNum)
{
    Node* temp = nullptr;

    if (count == 1)
    {
        temp = first;
        first = nullptr;
        last = first;
    }
    else
    {
        temp = findReservation(reservationNum);

        if (temp == first)
        {
            first = first->getNext();
            first->setPrev(nullptr);

        }
        else if (temp == last)
        {
            last = last->getPrev();
            last->setNext(nullptr);
        }
        else
        {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
        }
    }

    --count;
    delete temp;
    temp = nullptr;
}

void Reservations::printReservation(int reservedNum,
    const HikeList& hikeList, const MemberList& memberList) const
{
    Node* findNode = findReservation(reservedNum);

    if (findNode == nullptr)
    {
        cout << "This reservation does not exists.\n";
    }
    else
    {
        hikeList.printByHikeName(findNode->getHikeName());
        int points = memberList.getPoints(findNode->getMemberID());
        cout << endl;
        if (points != 0)
        {
            double price = hikeList.getPrice(findNode->getHikeName());
            cout << "\n\tDiscounted price using points: $" << fixed
                << setprecision(2) << (price - (points / 100)) << '\n';
        }
    }
}

Node* Reservations::findReservation(int reservedNum) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getReservationNumber() == reservedNum)
        {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
}

void Reservations::setFirst(Node* newFirst)
{
    first = newFirst;
}

void Reservations::setLast(Node* newLast)
{
    last = newLast;
}

Node* Reservations::getFirst() const
{
    return first;
}

Node* Reservations::getLast() const
{
    return last;
}

int Reservations::getCount() const
{
    return count;
}

void Reservations::clearList()
{
    Node* temp = first;

    while (first)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;
    count = 0;
}

Reservations::~Reservations()
{
    clearList();
}



