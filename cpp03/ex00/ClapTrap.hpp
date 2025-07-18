#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name, 
                int hit_p, 
                int energy_p, 
                int attack_d);
        ClapTrap(const ClapTrap& src);
        ClapTrap& operator=(const ClapTrap& c);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName() const;
        int getHP() const;
        int getEP() const;
        int getAD() const;
    private:
        std::string _name;
        int _hit_p;
        int _energy_p;
        int _attack_d;
};

#endif