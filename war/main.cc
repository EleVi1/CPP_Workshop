#include "assassin.hh"
#include "knight.hh"
#include "soldier.hh"
int main()
{
    Soldier s1;
    Knight k1;
    Assassin a1;
    s1.scream();
    k1.scream();
    a1.scream();
    
    s1.print_state();
    k1.print_state();
    a1.print_state();

    s1.attack(k1);
    k1.attack(a1);
    a1.attack(s1);

    s1.print_state();
    k1.print_state();
    a1.print_state();
    
    return 0;
}
