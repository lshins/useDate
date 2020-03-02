#ifndef H_date
#define H_date

#include <iostream>

using namespace std;

class dateType
{

public:
	int dMonth, dDay, dYear, lastDay;
	void setDate();
	void printDate();
	void incYears();
	void incMonths();
	void incDays();
	int rMonth();
	int rDay();
	int rYear();
	int rLast();
	bool isLeapYear();
	bool nextIsLeapYear();
	dateType();
	~dateType();
};

#endif