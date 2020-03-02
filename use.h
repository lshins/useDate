#ifndef H_use
#define H_use

#include <iostream>
#include "date.h"

using namespace std;

class useDate : public dateType
{
public:
	int daysElapsed();
	int daysRemaining();
	void incDays();
	void incMonths();
	void incYears();
	void findNewDate(dateType);
	void menu(useDate, dateType);
	useDate();
	~useDate();
};

#endif