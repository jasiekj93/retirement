#include "Date.hpp"

using namespace retirement::core;

Date::Date(unsigned year, unsigned month, unsigned day)
    : day(day), month(month), year(year)
{

}

bool Date::operator==(const Date& d) const
{
    if (day != d.day)
        return false;
    if (month != d.month)
        return false;
    if (year != d.year)
        return false;

    return true;
}
