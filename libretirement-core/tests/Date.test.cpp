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
};

TEST(DateTest, constructor)
{
	Date d(1,2,3);

	CHECK_EQUAL(1, d.getDay());
	CHECK_EQUAL(2, d.getMonth());
	CHECK_EQUAL(3, d.getYear());
}
