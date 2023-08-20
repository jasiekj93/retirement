#pragma once

/**
 * @file Calculator.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Interval.hpp>
#include <libretirement/core/Date.hpp>

namespace retirement::core
{
	class Calculator
	{
	public:
		virtual ~Calculator() {}

		virtual Interval compute(const Date& later,
			const Date& sooner) const = 0;

		static Calculator* getInstance();

	protected:
		static Calculator* instance;
	};
}
