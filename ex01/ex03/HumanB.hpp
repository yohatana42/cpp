#ifndef HumanB_H
 #define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        HumanB(Weapon weapon, std::string name);
        void attack();
        void setweapon(Weapon weapon);
    private:
        std::string _name;
        Weapon _weapon;
        HumanB();
};

#endif