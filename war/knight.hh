#pragma once
#include "soldier.hh"

class Knight : public Soldier
{
public:
    Knight()
    {
        this->damage_points_ = 5;
        this->health_points_ = 20;
        this->scream_ = "Be quick or be dead!";
    }

private:
};
