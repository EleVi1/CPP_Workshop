#pragma once

#include "unordered_multimap.hh"

template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const
{
    return map_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const
{
    return map_.size();
}

template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::const_iterator,
          typename UnorderedMultimap<KeyType, ValueType>::const_iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType& key) const
{
    unsigned count = UnorderedMultimap::count(key);
    if (count == 0)
    {
        return std::make_pair(map_.end(), map_.end());
    }
    auto beg = map_.begin();
    auto end = map_.end();
    auto first = map_.begin();
    auto last = map_.begin();
    for (; beg != end; beg++)
    {
        if (beg->first == key)
        {
            first = beg;
            last = beg;
            for (unsigned i = 0; i < count; i++)
            {
                last++;
            }
            break;
        }
    }

    return std::make_pair(first, last);
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType& key,
                                                const ValueType& value)
{
    map_.emplace_back(std::make_pair(key, value));
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::count(const KeyType& key) const
{
    auto count = 0;
    auto beg = map_.begin();
    auto end = map_.end();
    for (; beg != end; beg++)
    {
        if (beg->first == key)
        {
            count++;
        }
    }
    return count;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear()
{
    map_.clear();
}
