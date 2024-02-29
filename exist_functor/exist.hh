#pragma once
#include <set>

template <class T>
class Exist
{
public:
    bool operator()(T p);

private:
    std::set<T> parameters;
};

#include "exist.hxx"
