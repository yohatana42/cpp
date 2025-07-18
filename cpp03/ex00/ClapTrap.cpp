# include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name, 
        int hit_p, 
        int energy_p, 
        int attack_d)
{
    this->_name = name;
    this->_hit_p = hit_p;
    this->_energy_p = energy_p;
    this->_attack_d = attack_d;
    std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    this->_name = src.getName();
    this->_hit_p = src.getHP();
    this->_energy_p = src.getEP();
    this->_attack_d = src.getAD();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    this->_name = src.getName();
    this->_hit_p = src.getHP();
    this->_energy_p = src.getEP();
    this->_attack_d = src.getAD();
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap ";
    std::cout << this->_name;
    std::cout << " attacks ";
    std::cout << target;
    std::cout << ", causing ";
    std::cout << damage;
    std::cout << "points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}

std::string ClapTrap::getName() const
{
    return (this->_name);
}

int ClapTrap::getHP() const
{
    return (this->_hit_p);
}

int ClapTrap::getEP() const
{
    return (this->_energy_p);
}

int ClapTrap::getAD() const
{
    return (this->_attack_d);
}