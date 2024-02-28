#pragma once
#include "for_each.hh"

template <class T, class U, class Function>
void my_foreach(T beg, U end, Function f)
{
    for (; beg < end; beg++)
    {
        f(*beg);
    }
}