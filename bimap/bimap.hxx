#pragma once
#include "bimap.hh"

template <typename Lhs, typename Rhs>
bool Bimap<Lhs, Rhs>::insert(const Lhs& vl, const Rhs& vr)
{
    if (lhs_.contains(vl) || rhs_.contains(vr))
    {
        return false;
    }
    lhs_.insert({ vl, vr });
    rhs_.insert({ vr, vl });
    return true;
}

template <typename Lhs, typename Rhs>
bool Bimap<Lhs, Rhs>::insert(const Rhs& vr, const Lhs& vl)
{
    if (lhs_.contains(vl) || rhs_.contains(vr))
    {
        return false;
    }
    lhs_.insert({ vl, vr });
    rhs_.insert({ vr, vl });
    return true;
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::erase(const Lhs& vl)
{
    bool removed = false;
    auto beg = lhs_.begin();
    auto fin = lhs_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == vl)
        {
            lhs_.erase(beg);
            removed = true;
            break;
        }
    }

    auto beg1 = rhs_.begin();
    auto fin1 = rhs_.end();
    for (; beg1 != fin1; beg1++)
    {
        if (beg1->second == vl)
        {
            rhs_.erase(beg1);
            removed = true;
            break;
        }
    }
    return removed ? 1 : 0;
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::erase(const Rhs& vr)
{
    bool removed = false;
    auto beg = lhs_.begin();
    auto fin = lhs_.end();
    for (; beg != fin; beg++)
    {
        if (beg->second == vr)
        {
            lhs_.erase(beg);
            removed = true;
            break;
        }
    }

    auto beg1 = rhs_.begin();
    auto fin1 = rhs_.end();
    for (; beg1 != fin1; beg1++)
    {
        if (beg1->first == vr)
        {
            rhs_.erase(beg1);
            removed = true;
            break;
        }
    }
    return removed ? 1 : 0;
}

template <typename Lhs, typename Rhs>
typename Bimap<Lhs, Rhs>::iteratorLhs Bimap<Lhs, Rhs>::find(const Lhs& vl) const
{
    auto beg = lhs_.begin();
    auto fin = lhs_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == vl)
        {
            return beg;
        }
    }
    return fin;
}

template <typename Lhs, typename Rhs>
typename Bimap<Lhs, Rhs>::iteratorRhs Bimap<Lhs, Rhs>::find(const Rhs& vr) const
{
    auto beg = rhs_.begin();
    auto fin = rhs_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == vr)
        {
            return beg;
        }
    }
    return fin;
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::size() const
{
    return lhs_.size();
}

template <typename Lhs, typename Rhs>
void Bimap<Lhs, Rhs>::clear()
{
    lhs_.clear();
    rhs_.clear();
}

template <typename Lhs, typename Rhs>
const typename Bimap<Lhs, Rhs>::mapLhs& Bimap<Lhs, Rhs>::get_lhs() const
{
    return lhs_;
}

template <typename Lhs, typename Rhs>
const typename Bimap<Lhs, Rhs>::mapRhs& Bimap<Lhs, Rhs>::get_rhs() const
{
    return rhs_;
}