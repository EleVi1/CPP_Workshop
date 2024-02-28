#include "closer_to.hh"

#include <algorithm>
#include <iostream>
#include <vector>

CloserTo::CloserTo(int i)
{
    this->i_ = i;
}

bool CloserTo::operator()(int a, int b) const
{
    if (abs(a - i_) == abs(b - i_))
    {
        return a < b;
    }
    else
    {
        if (abs(a - i_) < abs(b - i_))
        {
            return true;
        }
        return false;
    }
}
