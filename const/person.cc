#include "person.hh"

std::string Person::get_name() const
{
    return name_;
}

unsigned int Person::get_age() const
{
    return age_;
}

void Person::set_name(std::string name)
{
    name_ = name;
}

void Person::set_age(unsigned int age)
{
    age_ = age;
}
