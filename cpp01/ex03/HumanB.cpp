#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name) {}


void HumanB::attack()
{
	std::cout << this->_name + " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
