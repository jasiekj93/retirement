#include "OutputImpl.hpp"
#include <iostream>

using namespace retirement::core;

OutputImpl::OutputImpl()
{
	instance = this;
}

void OutputImpl::print(const std::string& str)
{
	std::cout << str;
}
