#pragma once

/**
 * @file CalculatorImpl.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-20
 */

#include <libretirement/core/Calculator.hpp>

namespace retirement::core
{
	class CalculatorImpl : public Calculator
	{
	public:
		CalculatorImpl();

		Interval compute(const Date& later,
			const Date& sooner) const override;
	};
}
