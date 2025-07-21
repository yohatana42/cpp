#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_p = 100;
	this->_energy_p = 50;
	this->_attack_d = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	this->_name = src.getName();
	this->_hit_p = src.getHP();
	this->_energy_p = src.getEP();
	this->_attack_d = src.getAD();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	this->_name = src.getName();
	this->_hit_p = src.getHP();
	this->_energy_p = src.getEP();
	this->_attack_d = src.getAD();
	return (*this);
}

ScavTrap::~ScavTrap() {}

void ScavTrap::attack(ScavTrap *enemy)
{
	std::cout << _name + " ATTACK " + enemy->getName() << std::endl;
	enemy->takeDamage(_attack_d);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
