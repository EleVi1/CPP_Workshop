#pragma once

#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string& name, unsigned int age);
    std::string get_name() const;
    unsigned int get_age() const;

    void set_name(const std::string& name);
    void set_age(unsigned int age);

private:
    std::string name_;
    unsigned int age_;
};
