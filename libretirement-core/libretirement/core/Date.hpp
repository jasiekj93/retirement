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
		Date(unsigned day, unsigned month, unsigned year);

		constexpr auto getDay() const { return day; }
		constexpr auto getMonth() const { return month; }
		constexpr auto getYear() const { return year; }

	private:
		unsigned day, month, year;
	};
}
