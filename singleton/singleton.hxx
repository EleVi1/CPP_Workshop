#pragma once
#include "singleton.hh"

template <typename U>
U& Singleton<U>::instance()
{
    static U log;
    return log;
}