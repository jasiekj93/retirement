#include "Output.hpp"
#include <assert.h>

using namespace retirement::core;

Output* Output::instance = nullptr;

Output* Output::getInstance()
{
    assert(instance);
    return instance;
}
