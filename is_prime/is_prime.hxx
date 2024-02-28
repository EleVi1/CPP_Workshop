#pragma once
#include "is_prime.hh"

constexpr bool is_prime(unsigned int a)
{
    if (a == 1 || a == 0)
    {
        return false;
    }
    unsigned int i = 2;
    unsigned int reste = 0;
    while (i <= a / 2)
    {
        reste = a % i;
        if (reste == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}