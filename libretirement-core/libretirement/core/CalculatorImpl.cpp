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

    // while (date.getDay() != later.getDay())
    // {
    //     date.addDay(); 
    //     result.days++;
    // }

    return result;
}
