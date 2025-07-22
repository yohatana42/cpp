#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
	_name = name;
	_hit_p = 100;
	_energy_p = 100;
	_attack_d = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
{
	_name = src.getName();
	_hit_p = src.getHP();
	_energy_p = src.getEP();
	_attack_d = src.getAD();
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	_name = src.getName();
	_hit_p = src.getHP();
	_energy_p = src.getEP();
	_attack_d = src.getAD();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void highFivesGuys()
{
	std::cout << "highFivesGuys!" << std::endl;
}
