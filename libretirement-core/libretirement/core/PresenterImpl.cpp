#include "PresenterImpl.hpp"
#include <libretirement/core/Output.hpp>
#include <sstream>

using namespace retirement::core;

PresenterImpl::PresenterImpl()
	: interval()
{
	instance = this;
}

void PresenterImpl::display(const Interval& interval) 
{
	this->interval = interval;

	std::stringstream stream;
	stream << "Do emerytury "
		<< getProperLeftWord(getProperNumber())
		<< processYears()
		<< processMonths()
		<< processDays()
		<< "!\n";

	Output::getInstance()->print(stream.str());
}

std::string PresenterImpl::getProperLeftWord(unsigned number) const
{
	switch(number)
	{
	case 1:
		return "pozostał ";
	case 2:
	case 3:
	case 4:
		return "pozostały ";
	default:
		return "pozostało ";
	}
}

std::string PresenterImpl::getProperDaysWord() const
{
    return (interval.days == 1 ? " dzień" : " dni");
}

std::string PresenterImpl::getProperMonthsWord() const
{
    switch (interval.months)
	{
	case 1:
		return " miesiąc";
	case 2:
	case 3:
	case 4:
		return " miesiące";
	default:
		return " miesięcy";
	}
}

std::string PresenterImpl::getProperYearsWord() const
{
    switch (interval.years)
	{
	case 1:
		return " rok";
	case 2:
	case 3:
	case 4:
		return " lata";
	default:
		return " lat";
	}
}

unsigned retirement::core::PresenterImpl::getProperNumber() const
{
    if(interval.years)
		return interval.years;
    else if(interval.months)
		return interval.months;
	else
		return interval.days;
}

std::string PresenterImpl::processDays() const
{
	if(interval.days == 0)
		return processZeroDays();

	std::stringstream stream;

	if(interval.months || interval.years) 
		stream << " i ";

	stream << interval.days
		<< getProperDaysWord();

	return stream.str();
}

std::string PresenterImpl::processZeroDays() const
{
	if(interval.months == 0 && interval.years == 0)
		return "0 dni";
	else
		return std::string();
}

std::string PresenterImpl::processMonths() const
{
	if(interval.months == 0)
		return std::string();

	std::stringstream stream;

	stream << getMonthsSeparator()
		<< interval.months
		<< getProperMonthsWord();

	return stream.str();
}

std::string PresenterImpl::processYears() const
{
	if(interval.years == 0)
		return std::string();
	
	std::stringstream stream;

	stream << interval.years
		<< getProperYearsWord();

	return stream.str();
}

std::string PresenterImpl::getMonthsSeparator() const
{
	if(interval.years)
		return (interval.days ? ", " : " i ");
	else
		return std::string();
}
