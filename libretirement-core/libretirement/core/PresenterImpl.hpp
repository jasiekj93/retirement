#pragma once

/**
 * @file PresenterImpl.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Presenter.hpp>
#include <string>

namespace retirement::core
{
	class PresenterImpl : public Presenter
	{
	public:
		PresenterImpl();

		void display(const Interval&) override;
	
	protected:
		std::string getProperLeftWord(unsigned) const; 
		std::string getProperDaysWord() const; 
		std::string getProperMonthsWord() const; 
		std::string getProperYearsWord() const; 
		unsigned getProperNumber() const;
		std::string processDays() const;
		std::string processZeroDays() const;
		std::string processMonths() const;
		std::string processYears() const;
		std::string getMonthsSeparator() const;

	private:
		Interval interval;
	};
}
