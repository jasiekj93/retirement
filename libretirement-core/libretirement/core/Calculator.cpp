#include "Calculator.hpp"
#include <assert.h>

using namespace retirement::core;

Calculator* Calculator::instance = nullptr;

Calculator* Calculator::getInstance()
{
    assert(instance);
    return instance;
}
