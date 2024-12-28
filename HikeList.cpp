/*
	Alpha Team

	Pham, Kayden
	Pham, Cecilia
	Luong, Nhu

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "HikeList.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void HikeList::addHike(const Hike& hike, double newPrice)
{
	myHikeList.insert(make_pair(hike, newPrice));
}

void HikeList::addHike(const string& newLocation,
	const string& newName, int newDuration,
	char difficulty, double newPrice)
{
	Hike newHike(newLocation, newName, newDuration, difficulty);
	myHikeList.insert(make_pair(newHike, newPrice));
}

double HikeList::getPrice(const string& searchName) const
{
	auto toFind = find_if(myHikeList.begin(), myHikeList.end(),
		[&searchName](pair<Hike, double> it)
		{ return (it.first).getName() == searchName; });
	return toFind->second;
}

void HikeList::printAllLocations() const
{
	auto iter = myHikeList.begin();
	auto end = myHikeList.end();

	while (iter != end)
	{
		cout << "	" << iter->first.getLocation() << '\n';
		iter = myHikeList.upper_bound(iter->first);
	}
}

void HikeList::printByLocation(const string& location) const
{
	bool duplicate = false;
	auto toFind = find_if(myHikeList.begin(), myHikeList.end(),
		[&location](pair<Hike, double> elem)
		{ return (elem.first).getLocation() == location; });

	while (!duplicate && toFind->first.getLocation() == location)
	{
		cout << toFind->first
			<< "\t  Price (per person): $ " << fixed
			<< setprecision(2) << toFind->second << '\n' << endl;
		++toFind;
		if (toFind == myHikeList.end())
			duplicate = true;
	}
}

void HikeList::printByDuration() const
{
	auto iter = myHikeList.begin();
	auto end = myHikeList.end();
	multimap<int, string> durationList;

	while (iter != end)
	{
		string hikeDetail = iter->first.getName() + ", " 
			+ iter->first.getLocation();
		pair<int, string> myPair = 
			make_pair(iter->first.getDuration(), hikeDetail);
		durationList.insert(myPair);
		++iter;
	}

	for_each(durationList.begin(), durationList.end(),
		[](pair<int, string> durationPair) { cout << "\t(" << durationPair.first
		<< ") " << durationPair.second << endl; });
}

void HikeList::printByDuration(int days) const
{
	for (pair<Hike, double> elem : myHikeList)
	{
		string difficulty;
		if (elem.first.getDifficulty() == 'e')
			difficulty = "easy\n";
		else if (elem.first.getDifficulty() == 'm')
			difficulty = "moderate\n";
		else
			difficulty = "strenuous\n";

		if (elem.first.getDuration() == days)
		{
			cout << "\n\t" << elem.first.getName() << " ("
				<< elem.first.getLocation() << ")\n" 
				<< "\t  Difficulty: " << difficulty
				<< "\t  Duration: " << days << " day(s)\n";
		}
	}
}

void HikeList::printByDifficulty(char difficulty) const
{
	for (pair<Hike, double> elem : myHikeList)
	{
		if (elem.first.getDifficulty() == difficulty)
		{
			cout << "\t(" << difficulty << ") " << elem.first.getName()
				<< ", " << elem.first.getLocation() << endl;
		}
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> priceList;

	for(pair<Hike, double> elem : myHikeList)
	{
		pair<string, string> locationPair = make_pair(
			elem.first.getLocation(), elem.first.getName());
		pair<double, pair<string, string>> myPair = make_pair(
			elem.second, locationPair);
		priceList.emplace(myPair);
	}

	for(pair<double, pair<string, string>> elem : priceList)
	{
		cout << "\t$" << fixed << setprecision(2) << setw(8)
			<< elem.first << " - " << elem.second.first << " ("
			<< elem.second.second << ')' << endl;
	}	
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto toFind = find_if(myHikeList.begin(), myHikeList.end(),
		[&hikeName](pair<Hike, double> iter)
		{ return (iter.first).getName() == hikeName; });
	cout << fixed << setprecision(2)
		<< toFind->first << "\t  $" << toFind->second;
}

void HikeList::clearList()
{
	myHikeList.clear();
}

HikeList::~HikeList() {}


