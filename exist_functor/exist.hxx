#pragma once
#include "exist.hh"

template <class T>
bool Exist<T>::operator()(T p)
{
    if (parameters.contains(p))
    {
        return true;
    }
    parameters.insert(p);
    return false;
}