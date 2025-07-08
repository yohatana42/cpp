# include "Zombie.hpp"

Zombie::Zombie() : _name("bbb") {}

Zombie::Zombie(std::string name) : _name(name) {}

void Zombie::announce()
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
