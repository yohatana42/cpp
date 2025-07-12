#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::HumanB(Weapon weapon, std::string name)
{
    this->_weapon = weapon;
    this->_name = name;
}

void HumanB::attack()
{

}