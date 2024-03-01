#pragma once

#include "safe_int.hh"

// stl
#include <limits>
#include <optional>

inline SafeInt::SafeInt()
    : value_{}
{}

inline SafeInt::SafeInt(int value)
    : value_{ value }
{}

inline int SafeInt::operator*() const
{
    return *value_;
}

inline int SafeInt::value() const
{
    return value_.value();
}

inline int SafeInt::value_or(int value) const
{
    return value_.value_or(value);
}

inline bool SafeInt::has_value() const
{
    return value_.has_value();
}

inline SafeInt operator+(SafeInt lhs, SafeInt rhs)
{
    if (!lhs.has_value() || !rhs.has_value())
    {
        return SafeInt();
    }
    int val_res = 0;
    if (__builtin_add_overflow(lhs.value(), rhs.value(), &val_res))
    {
        return SafeInt();
    }
    return SafeInt(lhs.value() + rhs.value());
}

inline SafeInt operator-(SafeInt lhs, SafeInt rhs)
{
    if (!lhs.has_value() || !rhs.has_value())
    {
        return SafeInt();
    }
    int val_res = 0;
    if (__builtin_sub_overflow(lhs.value(), rhs.value(), &val_res))
    {
        return SafeInt();
    }
    return SafeInt(lhs.value() - rhs.value());
}

inline SafeInt operator*(SafeInt lhs, SafeInt rhs)
{
    if (!lhs.has_value() || !rhs.has_value())
    {
        return SafeInt();
    }
    int val_res = 0;
    if (__builtin_mul_overflow(lhs.value(), rhs.value(), &val_res))
    {
        return SafeInt();
    }
    return SafeInt(lhs.value() * rhs.value());
}

inline SafeInt operator/(SafeInt lhs, SafeInt rhs)
{
    if (!lhs.has_value() || !rhs.has_value())
    {
        return SafeInt();
    }
    if (rhs.value() == 0
        || (rhs.value() == -1
            && lhs.value() == std::numeric_limits<int>::min()))
    {
        return SafeInt();
    }
    return SafeInt(lhs.value() / rhs.value());
}

inline SafeInt& SafeInt::operator+=(SafeInt rhs)
{
    return (*this = *this + rhs);
}

inline SafeInt& SafeInt::operator-=(SafeInt rhs)
{
    return (*this = *this - rhs);
}

inline SafeInt& SafeInt::operator*=(SafeInt rhs)
{
    return (*this = *this * rhs);
}

inline SafeInt& SafeInt::operator/=(SafeInt rhs)
{
    return (*this = *this / rhs);
}

inline SafeInt& SafeInt::operator++()
{
    return *this += 1;
}

inline SafeInt& SafeInt::operator--()
{
    return *this -= 1;
}

inline SafeInt SafeInt::operator++(int)
{
    SafeInt result{ *this };
    ++*this;
    return result;
}

inline SafeInt SafeInt::operator--(int)
{
    SafeInt result{ *this };
    --*this;
    return result;
}

inline SafeInt SafeInt::operator+() const
{
    return *this;
}

inline SafeInt SafeInt::operator-() const
{
    return 0 - *this;
}
