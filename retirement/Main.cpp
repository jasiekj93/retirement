/**
 * @file Main.cpp
 * @author Adrian Szczepanski
 * @date 2023-08-20
 */

#include <libretirement/core/OutputImpl.hpp>
#include <libretirement/core/PresenterImpl.hpp>
#include <libretirement/core/SystemImpl.hpp>
#include <libretirement/core/CalculatorImpl.hpp>
#include <libretirement/core/Program.hpp>

using namespace retirement;
using namespace retirement::core;

int main(int argc, char* argv[])
{
	OutputImpl output;
	PresenterImpl presenter;
	SystemImpl system;
	CalculatorImpl calc;

	Date retirementDate(2027, 8, 23);

	Program().execute(retirementDate);

	return 0;
}
