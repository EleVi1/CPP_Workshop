#include "int_container.hh"

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    for (size_t i = 0; i < current_size_ - 1; ++i)
    {
        std::cout << elems_[i] << '|';
    }
    std::cout << elems_[current_size_ - 1];
    std::cout << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}
bool MyIntContainer::add(int elem)
{
    if (current_size_ == max_size_)
        return false;
    elems_[current_size_] = elem;
    current_size_++;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (elems_ == nullptr)
    {
        return std::nullopt;
    }
    int res;
    if (current_size_ == 0)
    {
        res = elems_[current_size_];
    }
    else
    {
        res = elems_[current_size_ - 1];
        current_size_--;
    }
    return res;
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
    {
        return std::nullopt;
    }
    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elems_[i] == elem)
        {
            return i;
        }
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    int size = current_size_;
    int i = 1;
    int j;
    int tmp;
    while (i < size)
    {
        j = i;
        while (j > 0 && elems_[j - 1] > elems_[j])
        {
            tmp = elems_[j];
            elems_[j] = elems_[j - 1];
            elems_[j - 1] = tmp;
            j--;
        }
        i++;
    }
}

bool MyIntContainer::is_sorted() const
{
    size_t i = 1;
    while (i < current_size_)
    {
        if (elems_[i - 1] > elems_[i])
        {
            return false;
        }
        i++;
    }
    return true;
}