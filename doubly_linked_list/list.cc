#include "list.hh"

#include <iostream>
#include <optional>
#include <ostream>

List::List()
{
    nb_elts_ = 0;
    this->first_ = nullptr;
    this->last_ = nullptr;
}

void List::push_front(int i)
{
    auto added = std::make_shared<Node>(Node(i));
    if (first_ != nullptr)
    {
        first_->set_prev(added);
    }
    added->set_next(first_);
    added->set_prev(nullptr);
    first_ = added;
    if (nb_elts_ == 0)
    {
        this->last_ = added;
    }
    nb_elts_++;
}

void List::push_back(int i)
{
    auto added = std::make_shared<Node>(Node(i));
    if (last_ != nullptr)
    {
        last_->set_next(added);
    }
    added->set_prev(last_);
    added->set_next(nullptr);
    last_ = added;
    if (nb_elts_ == 0)
    {
        this->first_ = added;
    }
    nb_elts_++;
}

std::optional<int> List::pop_back()
{
    if (first_ == nullptr)
    {
        return std::nullopt;
    }
    int val = this->last_->get_val();
    this->last_ = last_->get_prev();
    this->last_->set_next(nullptr);
    nb_elts_--;
    return val;
}

std::optional<int> List::pop_front()
{
    if (first_ == nullptr)
    {
        return std::nullopt;
    }
    int val = this->first_->get_val();
    this->first_ = first_->get_next();
    this->first_->set_prev(nullptr);
    nb_elts_--;
    return val;
}

void List::print(std::ostream& os) const
{
    if (nb_elts_ == 0)
    {
        return;
    }
    auto tmp = this->first_;
    size_t i = 0;
    while (i < this->nb_elts_ - 1)
    {
        os << tmp->get_val() << ' ';
        i++;
        tmp = tmp->get_next();
    }
    os << tmp->get_val() << '\n';
}

size_t List::length() const
{
    return nb_elts_;
}
