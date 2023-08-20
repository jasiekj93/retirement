#include "System.hpp"
#include <assert.h>

using namespace retirement::core;

System* System::instance = nullptr;

System* System::getInstance()
{
    assert(instance);
    return instance;
}
