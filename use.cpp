#include <iostream>
#include "date.h"
#include "use.h"

using namespace std;

int useDate::daysElapsed()
{
	int days = 0;
	switch (rMonth())
	{
	case 12:
		days += 30;
	case 11:
		days += 31;
	case 10:
		days += 30;
	case 9:
		days += 31;
	case 8:
		days += 31;
	case 7:
		days += 30;
	case 6:
		days += 31;
	case 5:
		days += 30;
	case 4:
		days += 31;
	case 3:
		if (isLeapYear())
			days += 29;
		else
			days += 28;
	case 2:
		days += 31;
	case 1:
		days += rDay();
	}
	return days;
}

int useDate::daysRemaining()
{
	int daysInYear;
	if (isLeapYear())
		daysInYear = 366;
	else
		daysInYear = 365;
	return (daysInYear - daysElapsed());
}

void useDate::incDays()
{
	dateType::incDays();
}

void useDate::incMonths()
{
	dateType::incMonths();
}

void useDate::incYears()
{
	dateType::incYears();
}

void useDate::findNewDate(dateType current)
{
	dateType newDate = current;
	int dateInt, nDDay, y, m, d, i;
	cout << "Input the number of days ahead of the current date to find a new date." << endl << endl;
	cin >> dateInt;
	while (dateInt <= 0)
	{
		cout << endl << endl;
		cout << "Invalid number of days. Please input the number of days ahead of the current date to find a new date." << endl << endl;
		cin >> dateInt;
	}
	cout << endl << endl;
	nDDay = newDate.dDay + dateInt;
	y = nDDay;
	while (y > 0)
	{
		if (((newDate.isLeapYear() && newDate.rMonth() <= 2)) || ((newDate.nextIsLeapYear() && newDate.rMonth() > 2)))
			y -= 366;
		else
			y -= 365;
		if (y >= 0)
		{
			newDate.incYears();
			nDDay = y;
		}
	}
	m = nDDay;
	while (m > 0)
	{
		if (newDate.rMonth() <= 7)
		{
			if (newDate.rMonth() % 2 == 1)
				m -= 31;
			else if (newDate.rMonth() == 2)
			{
				if (newDate.isLeapYear())
					m -= 29;
				else
					m -= 28;
			}
			else
				m -= 30;
		}
		else
			if (newDate.rMonth() % 2 == 1)
				m -= 30;
			else
				m -= 31;
		if (m >= 0)
		{
			newDate.incMonths();
			if (newDate.rMonth() > 12)
			{
				newDate.incYears();
				newDate.dMonth = 1;
			}
			nDDay = m;
		}
	}
	if (newDate.rMonth() <= 7)
	{
		if (newDate.rMonth() % 2 == 1)
			newDate.lastDay = 31;
		else if (newDate.rMonth() == 2)
		{
			if (newDate.isLeapYear())
				newDate.lastDay = 29;
			else
				newDate.lastDay = 28;
		}
		else
			newDate.lastDay = 30;
	}
	else
		if (newDate.rMonth() % 2 == 1)
			newDate.lastDay = 30;
		else
			newDate.lastDay = 31;
	d = nDDay;
	for (i = 0; i < d; i++)
	{
		newDate.incDays();
		if (newDate.dDay > newDate.lastDay)
		{
			newDate.incMonths();
			if (newDate.rMonth() <= 7)
			{
				if (newDate.rMonth() % 2 == 1)
					newDate.lastDay = 31;
				else if (newDate.rMonth() == 2)
				{
					if (newDate.isLeapYear())
						newDate.lastDay = 29;
					else
						newDate.lastDay = 28;
				}
				else
					newDate.lastDay = 30;
			}
			else
				if (newDate.rMonth() % 2 == 1)
					newDate.lastDay = 30;
				else
					newDate.lastDay = 31;
			newDate.dDay = 1;
		}
	}
	cout << "The date " << dateInt << " days from " << current.rMonth() << "/" << current.rDay() << "/" << current.rYear() << " is " << newDate.rMonth() << "/" << newDate.rDay() << "/" << newDate.rYear() << "." << endl << endl;
}

void useDate::menu(useDate date1p, dateType datep)
{
	char b = '0';
	do
	{
		cout << "To set the date, press '0'." << endl;
		cout << "To print the date, press '1'." << endl;
		cout << "To return the month, press '2'." << endl;
		cout << "To return the day, press '3'." << endl;
		cout << "To return the year, press '4'." << endl;
		cout << "To test whether the year is a leap year, press '5'." << endl;
		cout << "To find out how many days are in the month, press '6'." << endl;
		cout << "To find out how many days have elapsed in the year, press '7'." << endl;
		cout << "To find out how many days remain in the year, press '8'." << endl;
		cout << "To calculate a new date, press '9'." << endl;
		cout << "To terminate the program, press '#'." << endl;
		cout << endl;
		cin >> b;
		cout << endl << endl;
		switch (b)
		{
		case '0':
			date1p.setDate();
			datep.dMonth = date1p.dMonth;
			datep.dDay = date1p.dDay;
			datep.dYear = date1p.dYear;
			datep.lastDay = date1p.lastDay;
			break;
		case '1':
			date1p.printDate();
			break;
		case '2':
			cout << "The month is " << date1p.rMonth() << "." << endl << endl;
			break;
		case '3':
			cout << "The day is " << date1p.rDay() << "." << endl << endl;
			break;
		case '4':
			cout << "The year is " << date1p.rYear() << "." << endl << endl;
			break;
		case '5':
			if (date1p.isLeapYear())
				cout << "This year is a leap year!" << endl << endl;
			else
				cout << "This year is not a leap year..." << endl << endl;
			break;
		case '6':
			cout << "There are " << date1p.rLast() << " days in month " << date1p.rMonth() << "." << endl << endl;
			break;
		case '7':
			cout << date1p.daysElapsed() << " days have elapsed this year." << endl << endl;
			break;
		case '8':
			cout << date1p.daysRemaining() << " days remain in this year." << endl << endl;
			break;
		case '9':
			findNewDate(datep);
			break;
		case '#':
			cout << "Program terminated." << endl << endl;
			break;
		default:
			cout << "Invalid input. Please follow the instructions in the menu." << endl << endl;
		}
	} while (b != '#');
}

useDate::useDate()
{
	dMonth = 1;
	dDay = 1;
	dYear = 2000;
	lastDay = 31;
}

useDate::~useDate()
{

}