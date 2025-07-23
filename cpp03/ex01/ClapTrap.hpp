#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		ClapTrap& operator=(const ClapTrap& c);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		unsigned int getHP() const;
		unsigned int getEP() const;
		unsigned int getAD() const;
	protected:
		std::string _name;
		unsigned int _hit_p;
		unsigned int _energy_p;
		unsigned int _attack_d;
};

#endif
