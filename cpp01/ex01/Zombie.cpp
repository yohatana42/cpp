# include "Zombie.hpp"

Zombie::Zombie() : _name("bbb") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_name;
	std::cout << ": death!!!" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}
