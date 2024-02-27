#pragma once

#include "soldier.hh"

class Assassin : public Soldier
{
public:
    Assassin()
    {
        this->damage_points_ = 9;
        this->health_points_ = 10;
        this->scream_ = "Out of the shadows!";
    }

private:
};