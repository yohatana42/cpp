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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_p == 0)
	{
		std::cout << _name + " is no HP" << std::endl;
		return ;
	}
	if (_energy_p == 0)
	{
		std::cout << _name + " is no EP" << std::endl;
		return ;
	}
	std::cout << _name + " ATTACK " + target << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
