/**
 * @file Date.test.cpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Date.hpp>

#include <CppUTest/TestHarness.h>

using namespace retirement::core;

TEST_GROUP(DateTest)
{
	void setup()
	{

	}

	void teardown()
	{
		
	}

	void checkAddDay(const Date& expected, const Date& actual)
	{
		Date date(actual);
		date.addDay();
		CHECK(expected == date);
	}

	void checkAddMonth(const Date& expected, const Date& actual)
	{
		Date date(actual);
		date.addMonth();
		CHECK(expected == date);
	}
};

TEST(DateTest, constructor)
{
	Date d(1,2,3);

	CHECK_EQUAL(1, d.getYear());
	CHECK_EQUAL(2, d.getMonth());
	CHECK_EQUAL(3, d.getDay());
}

TEST(DateTest, operatorEqual)
{
	CHECK(Date(1,2,3) == Date(1,2,3));
	CHECK_FALSE(Date(1,2,3) == Date(2,2,3));
	CHECK_FALSE(Date(1,2,3) == Date(1,1,3));
	CHECK_FALSE(Date(1,2,3) == Date(1,2,2));
	CHECK_FALSE(Date(1,2,3) == Date(1,1,2));
	CHECK_FALSE(Date(1,2,3) == Date(4,5,6));
}

TEST(DateTest, operatorGreaterThan)
{
	CHECK(Date(1,2,3) > Date(1,2,2));
	CHECK_FALSE(Date(1,2,2) > Date(1,2,3));
	CHECK(Date(1,3,3) > Date(1,2,3));
	CHECK_FALSE(Date(1,2,3) > Date(1,3,3));
	CHECK(Date(2,2,3) > Date(1,2,3));
	CHECK_FALSE(Date(1,2,3) > Date(2,2,3));
	CHECK_FALSE(Date(1,10,3) > Date(2,3,3));
	CHECK_FALSE(Date(2,2,10) > Date(2,3,3));
}

TEST(DateTest, addDay_simple)
{
	checkAddDay(Date(2023, 1, 2),
		Date(2023, 1, 1));
}

TEST(DateTest, addDay_endOfMonth)
{
	checkAddDay(Date(2023, 2, 1),
		Date(2023, 1, 31));
}

TEST(DateTest, addDay_endOfMonth_30Days)
{
	checkAddDay(Date(2023, 5, 1),
		Date(2023, 4, 30));
	checkAddDay(Date(2023, 7, 1),
		Date(2023, 6, 30));
	checkAddDay(Date(2023, 10, 1),
		Date(2023, 9, 30));
	checkAddDay(Date(2023, 12, 1),
		Date(2023, 11, 30));
}

TEST(DateTest, addDay_endOfFebruary)
{
	checkAddDay(Date(2023, 3, 1),
		Date(2023, 2, 28));
}

TEST(DateTest, addDay_endOfFebruary_leapYear)
{
	checkAddDay(Date(2024, 2, 29),
		Date(2024, 2, 28));
}

TEST(DateTest, addDay_endOfFebruary_notLeapYear)
{
	checkAddDay(Date(1900, 3, 1),
		Date(1900, 2, 28));
}

TEST(DateTest, addDay_endOfYear)
{
	checkAddDay(Date(1901, 1, 1),
		Date(1900, 12, 31));
}

TEST(DateTest, addMonth)
{
	checkAddMonth(Date(1900, 4, 31),
		Date(1900, 3, 31));
}

TEST(DateTest, addMonth_endOfYear)
{
	checkAddMonth(Date(1901, 1, 31),
		Date(1900, 12, 31));
}

TEST(DateTest, addYear)
{
	Date date(2023, 3, 31);
	date.addYear();
	CHECK(Date(2024, 3, 31) == date);
}