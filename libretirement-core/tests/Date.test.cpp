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
