#include "OutputMock.hpp"

using namespace retirement::core;
using namespace retirement::core::mock;

OutputMock::OutputMock()
{
	instance = this;
}

void OutputMock::print(const std::string& s)
{
	text = s;
}
