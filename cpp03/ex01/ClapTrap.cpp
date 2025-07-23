# include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hit_p = 10;
    this->_energy_p = 10;
    this->_attack_d = 0;
    std::cout << "ClapTrap constructor called" << std::endl;
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
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_p == 0)
    {
        std::cout << "no HP..." << std::endl;
        return ;
    }
    if (this->_energy_p == 0)
    {
        std::cout << "no energy..." << std::endl;
        return ;
    }
    std::cout << "ClapTrap ";
    std::cout << this->_name;
    std::cout << " attacks ";
    std::cout << target;
    std::cout << ", causing ";
    std::cout << this->_attack_d;
    std::cout << " points of damage!" << std::endl;
    this->_energy_p = this->_energy_p - 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int temp = this->_hit_p - amount;

    std::cout << amount <<  " dameged!" << std::endl;
	if (temp <= 0)
		this->_hit_p = 0;
	else
		this->_hit_p = this->_hit_p - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_p == 0)
    {
        std::cout << "no HP..." << std::endl;
        return ;
    }
    if (this->_energy_p == 0)
    {
        std::cout << "no energy..." << std::endl;
        return ;
    }
    std::cout << amount <<  " Repaired" << std::endl;
    this->_hit_p = this->_hit_p + amount;
    this->_energy_p = this->_energy_p - 1;
}

std::string ClapTrap::getName() const
{
    return (this->_name);
}

unsigned int ClapTrap::getHP() const
{
    return (this->_hit_p);
}

unsigned int ClapTrap::getEP() const
{
    return (this->_energy_p);
}

unsigned int ClapTrap::getAD() const
{
    return (this->_attack_d);
}
