/**
 * @file SystemImpl.test.cpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/SystemImpl.hpp>
#include <ctime>

#include <CppUTest/TestHarness.h>

using namespace retirement::core;

TEST_GROUP(SystemImplTest)
{
	void setup()
	{

	}

	void teardown()
	{
		
	}

	Date getCurrent()
	{
		time_t my_time;
		struct tm * date; 
		time (&my_time);
		date = localtime (&my_time);

		return {(unsigned)(date->tm_year + 1900),
			(unsigned)(date->tm_mon + 1),
			(unsigned)(date->tm_mday) };
	}
};

TEST(SystemImplTest, getDate)
{
	CHECK(SystemImpl().getDate() == getCurrent());	
}
