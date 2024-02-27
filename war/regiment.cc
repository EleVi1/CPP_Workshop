#include "regiment.hh"

void Regiment::add_soldier(Soldier& s)
{
    soldiers.emplace_back(s);
}

void Regiment::join_by(Regiment& r)
{
    for (auto& soldier : soldiers)
    {
        soldiers.emplace_back(soldier);
        r.soldiers.pop_back();
    }
}

size_t Regiment::count() const
{
    return soldiers.size();
}

void Regiment::print_state() const
{
    for (size_t i = 0; i < soldiers.size(); ++i)
    {
        soldiers[i].get().print_state();
    }
}

void Regiment::scream() const
{
    for (size_t i = 0; i < soldiers.size(); ++i)
    {
        soldiers[i].get().scream();
    }
}
