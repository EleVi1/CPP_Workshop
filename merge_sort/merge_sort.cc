#include "merge_sort.hh"

void merge_sort(iterator_type begin, iterator_type end)
{
    if (end - begin <= 1)
    {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);

    std::inplace_merge(begin, mid, end);
}