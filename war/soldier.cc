#include "soldier.hh"

Soldier::Soldier()
{
    this->damage_points_ = 3;
    this->health_points_ = 15;
    this->scream_ = "No pity for losers!";
}

void Soldier::attack(Soldier& s)
{
    s.health_points_ = s.health_points_ - damage_points_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << health_points_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << scream_ << '\n';
}
