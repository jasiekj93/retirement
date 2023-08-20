#pragma once

/**
 * @file Date.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

namespace retirement::core
{
	class Date
	{
	public:
		Date(unsigned year, unsigned month, unsigned day);

		constexpr auto getDay() const { return day; }
		constexpr auto getMonth() const { return month; }
		constexpr auto getYear() const { return year; }

		void addDay();
		void addMonth();
		void addYear();

		bool operator==(const Date&) const;
		bool operator>(const Date&) const;

	protected:
		void processEndOfShorterMonth(); 
		void processEndOfFebruary();
        void processEndOfStandardMonth();
		bool isLeapYear() const;

	private:
		unsigned day, month, year;
	};
}
