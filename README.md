# HikingInTheUS
An interactive Hiking trail recommendation system as part of the Data Structure course. Utilize object-oriented programming and abstract data types. Users can make adjustments to their profile as well as find and reserve hiking plans.

## Getting Started

### Dependencies

Any application or IDE that can compile and run C++ code. Examples include:
  - GCC (GNU Compiler Collection)
  - Microsoft Visual Studio

A .txt file with needed information for:
  - Hike list (with trail name, duration, type, and price).
  -  Member list (with member name and current point).

## Files Overview

### Interface
Responsible for displaying content and serving as the intermediary for all user actions.
### HikeReader
Read and process input files for hike information.
### HikeList
Add the hike to the list and display the hike list with the given filters: location, duration, difficulty, and hike's name. 
### MemberReader
Read and process input files for member information.
### MemberList
Add a member to the list, display and add points to a member, and  delete the member list. 
### Reservation
Using linked list to retrieve and set hike reservation and member information. 
