#include "CalculatorImpl.hpp"

using namespace retirement::core;

CalculatorImpl::CalculatorImpl()
{
	instance = this;
}

Interval CalculatorImpl::compute(const Date &later, const Date &sooner) const
{
    auto date = sooner;
    Interval result = { 0, 0, 0 };

    if(sooner > later)
        return result;

    while (date.getDay() != later.getDay())
    {
        date.addDay(); 
        result.days++;
    }

    while (date.getMonth() != later.getMonth())
    {
        date.addMonth(); 
        result.months++;
    }

    while (date.getYear() != later.getYear())
    {
        date.addYear(); 
        result.years++;
    }

    return result;
}
