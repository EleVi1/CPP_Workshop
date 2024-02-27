#include "soldier.hh"

class Knight : public Soldier
{
    int health_points_ = 20;
    int damage_points_ = 5;
    std::string scream_ = "Be quick or be dead!";
};