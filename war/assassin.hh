#include "soldier.hh"

class Assassin : public Soldier
{
    int health_points_ = 10;
    int damage_points_ = 9;
    std::string scream_ = "Out of the shadows!";
};
