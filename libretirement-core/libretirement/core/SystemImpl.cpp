#include "SystemImpl.hpp"
#include <ctime>

using namespace retirement::core;

SystemImpl::SystemImpl()
{
	instance = this;
}

Date SystemImpl::getDate() const
{
    time_t my_time;
    struct tm * date; 
    time (&my_time);
    date = localtime (&my_time);

    return {(unsigned)(date->tm_year + 1900),
        (unsigned)(date->tm_mon + 1),
        (unsigned)(date->tm_mday) };
}
