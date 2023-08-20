#include "Presenter.hpp"
#include <assert.h>

using namespace retirement::core;

Presenter* Presenter::instance = nullptr;

Presenter* Presenter::getInstance()
{
    assert(instance);
    return instance;
}
