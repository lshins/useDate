#include <iostream>
#include "date.h"

using namespace std;

void dateType::setDate()
{
	cout << "Input the desired date in \"month-day-year\" format." << endl << endl;
	cin >> dMonth >> dDay >> dYear;
	if (dMonth <= 7)
	{
		if (dMonth % 2 == 1)
			lastDay = 31;
		else if (dMonth == 2)
		{
			if (isLeapYear())
				lastDay = 29;
			else
				lastDay = 28;
		}
		else
			lastDay = 30;
	}
	else
		if (dMonth % 2 == 1)
			lastDay = 30;
		else
			lastDay = 31;
	cout << endl << endl;
}

void dateType::printDate()
{
	cout << dMonth << "/" << dDay << "/" << dYear << endl << endl;
}

void dateType::incDays()
{
	dDay++;
}

void dateType::incMonths()
{
	dMonth++;
}

void dateType::incYears()
{
	dYear++;
}

int dateType::rMonth()
{
	return dMonth;
}

int dateType::rDay()
{
	return dDay;
}

int dateType::rYear()
{
	return dYear;
}

int dateType::rLast()
{
	return lastDay;
}

bool dateType::isLeapYear()
{
	if (dYear % 4 == 0)
		if (dYear % 100 != 0)
			return true;
		else
			if (dYear % 1000 == 0)
				return true;
	return false;
}

bool dateType::nextIsLeapYear()
{
	if ((dYear + 1) % 4 == 0)
		if ((dYear + 1) % 100 != 0)
			return true;
		else
			if ((dYear + 1) % 1000 == 0)
				return true;
	return false;
}

dateType::dateType()
{
	dMonth = 1;
	dDay = 1;
	dYear = 2000;
	lastDay = 31;
}

dateType::~dateType()
{

}