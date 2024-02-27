#include "regiment.hh"

void Regiment::add_soldier(Soldier& s)
{
    soldiers.emplace_back(s);
}

void Regiment::join_by(Regiment& r)
{
    if (r.soldiers.empty())
    {
        return;
    }
    for (auto& soldier : soldiers)
    {
        soldiers.emplace_back(soldier);
    }
    r.soldiers.clear();
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
