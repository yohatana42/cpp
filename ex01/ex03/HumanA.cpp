#include "HumanA.hpp"

// 何を参照で持つべきなのかわからん＾＾


HumanA::HumanA(std::string name, Weapon& weapon)
{
	_name = name;
	this->_weapon = &weapon;
}

void HumanA::attack()
{
	std::cout << _name + " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}
