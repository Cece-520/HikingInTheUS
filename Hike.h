/*
    Alpha Team

    Pham, Kayden
    Pham, Cecilia
    Luong, Nhu

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike 
{
    friend std::ostream& operator<<(std::ostream&, const Hike&);
public:
    Hike() : duration(0), difficulty('e') {}
    Hike(const std::string&, const std::string&, int, char);

    std::string getLocation() const;
    std::string getName() const;
    int getDuration() const;
    char getDifficulty() const;

    bool operator<(const Hike&) const;

    ~Hike();
private:
    std::string location;
    std::string name;
    int duration;
    char difficulty;
};
#endif

