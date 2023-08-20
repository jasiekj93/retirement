/**
 * @file PresenterImpl.test.cpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/PresenterImpl.hpp>
#include <mock/OutputMock.hpp>

#include <CppUTest/TestHarness.h>

using namespace retirement::core;

TEST_GROUP(PresenterImplTest)
{
	mock::OutputMock* output;

	void setup()
	{
		output = new mock::OutputMock();
	}

	void teardown()
	{
		delete output;
	}

	void checkFor(const Interval& interval, const std::string& str)
	{
		PresenterImpl().display(interval);
		STRCMP_EQUAL(str.c_str(), output->text.c_str());
	}
};

TEST(PresenterImplTest, display_zeroDays)
{
	checkFor({0, 0, 0}, "Do emerytury pozostało 0 dni!\n"); 
}

TEST(PresenterImplTest, display_oneDay)
{
	checkFor({1, 0, 0}, "Do emerytury pozostał 1 dzień!\n"); 
}

TEST(PresenterImplTest, display_twoThreeFourDays)
{
	checkFor({2, 0, 0}, "Do emerytury pozostały 2 dni!\n"); 
	checkFor({3, 0, 0}, "Do emerytury pozostały 3 dni!\n"); 
	checkFor({4, 0, 0}, "Do emerytury pozostały 4 dni!\n"); 
}

TEST(PresenterImplTest, display_fiveOrMoreDays)
{
	checkFor({5, 0, 0}, "Do emerytury pozostało 5 dni!\n"); 
	checkFor({6, 0, 0}, "Do emerytury pozostało 6 dni!\n"); 
}

TEST(PresenterImplTest, display_oneMonthAndDays)
{
	checkFor({5, 1, 0}, "Do emerytury pozostał 1 miesiąc i 5 dni!\n"); 
}

TEST(PresenterImplTest, display_oneMonthOnly)
{
	checkFor({0, 1, 0}, "Do emerytury pozostał 1 miesiąc!\n"); 
}

TEST(PresenterImplTest, display_twoThreeFourMonthsAndDays)
{
	checkFor({5, 2, 0}, "Do emerytury pozostały 2 miesiące i 5 dni!\n"); 
	checkFor({5, 3, 0}, "Do emerytury pozostały 3 miesiące i 5 dni!\n"); 
	checkFor({5, 4, 0}, "Do emerytury pozostały 4 miesiące i 5 dni!\n"); 
}

TEST(PresenterImplTest, display_fiveOrMoreMonthsAndDays)
{
	checkFor({5, 5, 0}, "Do emerytury pozostało 5 miesięcy i 5 dni!\n"); 
	checkFor({5, 6, 0}, "Do emerytury pozostało 6 miesięcy i 5 dni!\n"); 
}

TEST(PresenterImplTest, display_oneYearAndDays)
{
	checkFor({5, 0, 1}, "Do emerytury pozostał 1 rok i 5 dni!\n"); 
}

TEST(PresenterImplTest, display_oneYearOnly)
{
	checkFor({0, 0, 1}, "Do emerytury pozostał 1 rok!\n"); 
}

TEST(PresenterImplTest, display_oneYearAndMonths)
{
	checkFor({0, 2, 1}, "Do emerytury pozostał 1 rok i 2 miesiące!\n"); 
}

TEST(PresenterImplTest, display_oneYearMonthsAndDays)
{
	checkFor({5, 2, 1}, "Do emerytury pozostał 1 rok, 2 miesiące i 5 dni!\n"); 
}

TEST(PresenterImplTest, display_twoThreeFourYears)
{
	checkFor({0, 0, 2}, "Do emerytury pozostały 2 lata!\n"); 
	checkFor({0, 0, 3}, "Do emerytury pozostały 3 lata!\n"); 
	checkFor({0, 0, 4}, "Do emerytury pozostały 4 lata!\n"); 
}

TEST(PresenterImplTest, display_fiveOrMoreYears)
{
	checkFor({0, 0, 5}, "Do emerytury pozostało 5 lat!\n"); 
	checkFor({0, 0, 6}, "Do emerytury pozostało 6 lat!\n"); 
}