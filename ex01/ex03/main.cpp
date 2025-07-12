#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon weapon("aaaaa");
    HumanA human_a(weapon, "A");
    HumanB *human_b = new HumanB("B");
    HumanB *human_c = new HumanB(weapon, "C");
    return (0);
}