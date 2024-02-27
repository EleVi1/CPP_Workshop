#include "soldier.hh"

void Soldier::attack(Soldier &s) {
    s.health_points_ -= this->damage_points_;
}

void Soldier::print_state() const {
    std::cout << "I have " << this->health_points_ << " health points.\n";
}

void Soldier::scream() const {
    std::cout << this->scream_;
}
