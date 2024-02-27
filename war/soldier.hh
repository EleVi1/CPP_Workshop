#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Soldier {
public:
    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    int health_points_ = 15;
    int damage_points_ = 3;
    std::string scream_ = "No pity for losers!";
};