/**
 * @file CalculatorImpl.test.cpp
 * @author Adrian Szczepanski
 * @date 2023-08-20
 */

#include <libretirement/core/CalculatorImpl.hpp>

#include <CppUTest/TestHarness.h>

using namespace retirement::core;

TEST_GROUP(CalculatorImplTest)
{
	void setup()
	{

	}

	void teardown()
	{
		
	}

	void checkFor(const Interval& interval, 
		const Date& later,
		const Date& sooner)
	{
		auto result = CalculatorImpl().compute(later, sooner);

		CHECK_EQUAL(interval.days, result.days);
		CHECK_EQUAL(interval.months, result.months);
		CHECK_EQUAL(interval.years, result.years);
	}
};

TEST(CalculatorImplTest, zeroDays)
{
	checkFor({0, 0, 0},
		{2023, 8, 19},
		{2023, 8, 19});
}

TEST(CalculatorImplTest, oneDay)
{
	checkFor({1, 0, 0},
		{2023, 8, 20},
		{2023, 8, 19});
}

TEST(CalculatorImplTest, twoDays)
{
	checkFor({2, 0, 0},
		{2023, 8, 21},
		{2023, 8, 19});
}

TEST(CalculatorImplTest, twoDays_endMonth)
{
	checkFor({2, 0, 0},
		{2023, 9, 1},
		{2023, 8, 30});
}

TEST(CalculatorImplTest, oneMonth)
{
	checkFor({0, 1, 0},
		{2023, 9, 1},
		{2023, 8, 1});
}

TEST(CalculatorImplTest, oneMonth_threeDays)
{
	checkFor({3, 1, 0},
		{2023, 9, 4},
		{2023, 8, 1});
}

TEST(CalculatorImplTest, oneMonth_threeDays_endOfYear)
{
	checkFor({3, 1, 0},
		{2024, 2, 3},
		{2023, 12, 31});
}

TEST(CalculatorImplTest, oneMonth_threeDays_shorterStartMonth)
{
	checkFor({31, 0, 0},
		{2023, 3, 31},
		{2023, 2, 28});
}

TEST(CalculatorImplTest, almostYear)
{
	checkFor({30, 11, 0},
		{2024, 1, 1},
		{2023, 1, 2});
}

TEST(CalculatorImplTest, oneYear_oneMonth_threeDays)
{
	checkFor({3, 1, 1},
		{2024, 9, 4},
		{2023, 8, 1});
}

TEST(CalculatorImplTest, laterDateIsActuallyPrevious)
{
	checkFor({0, 0, 0},
		{2023, 9, 4},
		{2024, 8, 1});
}
