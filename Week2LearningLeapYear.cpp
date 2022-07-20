// Week2LearningLeapYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

constexpr unsigned short int baseYear = 1900;

bool IsLeapYear(unsigned short int currentYear);
unsigned short int GetCurrentYear();
void DisplayYearMessage(bool isLeapYear, unsigned short int currentYear);

bool IsLeapYear(unsigned short int currentYear) 
{
	return (currentYear % 4 == 0) && ((currentYear % 100 != 0) || currentYear % 400 == 0);
}

unsigned short int GetCurrentYear() 
{
	// current date/time based on current system
	time_t currentTime = time(0);

	tm localTime;
	localtime_s(&localTime, &currentTime);

	return baseYear + localTime.tm_year;
}

void DisplayYearMessage(bool isLeapYear, unsigned short int currentYear) 
{
	std::string currentYearText = isLeapYear ? "" : "NOT ";

	cout << "The current year of " << currentYear << " is " << currentYearText << "a leap year.";
}

int main() 
{
	unsigned short int currentYear = GetCurrentYear();

	// testing various inputs
	// currentYear = 2020; // expected: IS a leap year - passes
	// currentYear = 2200; // expected: is NOT a leap year - passes
	// currentYear = 2000; // expected: IS a leap year - passes

	bool isLeapYear = IsLeapYear(currentYear);

	DisplayYearMessage(isLeapYear, currentYear);
}


