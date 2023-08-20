#include "Date.hpp"

using namespace retirement::core;

Date::Date(unsigned year, unsigned month, unsigned day)
    : day(day), month(month), year(year)
{

}

void Date::addDay()
{
    day++;
    
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        processEndOfShorterMonth(); 
        break;
    case 2:
        processEndOfFebruary();
        break;
    default:
        processEndOfStandardMonth();
        break;
    }
}

void Date::addMonth()
{
    month++;

    if (month > 12)
    {
        month = 1;
        year++;
    }
}

void Date::addYear()
{
    year++;
}

bool Date::operator==(const Date &d) const
{
    if (day != d.day)
        return false;
    if (month != d.month)
        return false;
    if (year != d.year)
        return false;

    return true;
}

bool Date::operator>(const Date& d) const
{
    if(year > d.year)
        return true;
    else if(year == d.year and
        month > d.month)
        return true;
    else if(year == d.year and
        month == d.month and
        day > d.day)
        return true;
    else
        return false;
}

void Date::processEndOfShorterMonth()
{
    if(day <= 30)
        return;

    day = 1;
    addMonth();
}

void Date::processEndOfFebruary()
{
    if((day > 28 and !isLeapYear()) or
        (day > 29 and isLeapYear()))
    {
        day = 1;
        addMonth();
    }

}

void Date::processEndOfStandardMonth()
{
    if(day <= 31)
        return;

    day = 1;
    addMonth();
}

bool Date::isLeapYear() const
{
    if(year % 4 != 0)
        return false;
    else if(year % 100 == 0 and
        year % 400 != 0)
        return false;
    else
        return true;
}
