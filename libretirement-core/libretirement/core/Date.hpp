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

		bool operator==(const Date&) const;

	private:
		unsigned day, month, year;
	};
}
