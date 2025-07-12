#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::HumanB(std::string name, Weapon weapon)
{
    // weaponはポインタっぽい？
    this->_weapon = weapon;
    this->_name = name;
}

void HumanB::attack()
{
    std::cout << this->_name + "attacks with their"; 
    std::cout << this->_weapon->_type << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}