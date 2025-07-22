#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

 #include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& src);
		~FragTrap();
		void highFivesGuys();
};

#endif
