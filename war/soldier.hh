#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Soldier
{
public:
    Soldier();
    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    int damage_points_;
    int health_points_;
    std::string scream_;
};