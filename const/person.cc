#include "person.hh"

Person::Person(const std::string& name, unsigned int age)
{
    name_ = name;
    age_ = age;
}

std::string Person::get_name() const
{
    return name_;
}

unsigned int Person::get_age() const
{
    return age_;
}

void Person::set_name(const std::string name)
{
    name_ = name;
}

void Person::set_age(const unsigned int age)
{
    age_ = age;
}
