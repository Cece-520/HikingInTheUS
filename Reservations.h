/*
    Alpha Team

    Pham, Kayden
    Pham, Cecilia
    Luong, Nhu
   

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int RESERVATION_NUMBER = 50001;

class Node
{
public:
    Node() :reservationNumber(0), memberID(0), next(nullptr), 
            prev(nullptr) {}
    Node(int newReservedNumber, int newMemberID, std::string newHikeName, 
        Node* prevNode, Node* nextNode) : 
        reservationNumber(newReservedNumber), memberID(newMemberID),
        hikeName(newHikeName), prev(prevNode), next(nextNode) {}
    int getReservationNumber() const { return reservationNumber; }
    int getMemberID() const { return memberID; }
    std::string getHikeName() const { return hikeName; }
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }
    void setReservationNumber(int num) { reservationNumber = num; }
    void setMemberID(int newID) { memberID = newID; }
    void setHikeName(std::string newHikeName) { hikeName = newHikeName; }
    void setNext(Node* nextNode) { next = nextNode; }
    void setPrev(Node* prevNode) { prev = prevNode; }
    ~Node() {}
private:
    int reservationNumber;
    int memberID;
    std::string hikeName;
    Node* next;
    Node* prev;
};

class Reservations
{
public:
    Reservations() : first(nullptr), last(nullptr), count(0) {}

    int addReservation(int newMemberID,
        const std::string& newHikeName);
    void cancelReservation(int reservationNum);

    void printReservation(int reservedNum, const HikeList& hikeList,
        const MemberList& memberList) const;

    void setFirst(Node* newFirst);
    void setLast(Node* newLast);

    Node* getFirst() const;
    Node* getLast() const;
    int getCount() const;

    void clearList();
    ~Reservations();
private:
    Node* findReservation(int reservedNum) const;
    Node* first;
    Node* last;
    int count;
};
#endif