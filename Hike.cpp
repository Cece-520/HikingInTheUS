/*
    Alpha Team

    Pham, Kayden
    Pham, Cecilia
    Luong, Nhu

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(std::ostream& out, const Hike& paramHike) 
{
    out << "\t" << paramHike.name << " (" << paramHike.location << ")\n"
        << "\t  Difficulty: ";

    if (paramHike.difficulty == 's')
        out << "strenuous\n";
    else if (paramHike.difficulty == 'm')
        out << "moderate\n";
    else if (paramHike.difficulty == 'e')
        out << "easy\n";

    out << "\t  Duration: " << paramHike.duration << " day(s)\n";
    return out;
}

Hike::Hike(const std::string& newLocation, const std::string& newName,
    int newDuration, char newDifficulty) 
{
    location = newLocation;
    name = newName;
    duration = newDuration;
    difficulty = newDifficulty;
}

bool Hike::operator<(const Hike& otherHike) const 
{
    return (location < otherHike.location);
}

std::string Hike::getLocation() const 
{
    return location;
}

std::string Hike::getName() const 
{
    return name;
}

int Hike::getDuration() const 
{
    return duration;
}

char Hike::getDifficulty() const 
{
    return difficulty;
}

Hike::~Hike() {}
