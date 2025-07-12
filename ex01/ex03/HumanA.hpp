#ifndef HUMANA_H
 #define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(Weapon weapon, std::string name);
        void attack();
    private:
        HumanA();
        std::string _name;
        Weapon _wepon;
};

#endif