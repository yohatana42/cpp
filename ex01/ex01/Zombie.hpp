#ifndef ZOMBIE_H
 #define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		void announce();
		void set_name(std::string name);
	private:
		std::string _name;
};

	Zombie *zombieHorde(int n, std::string name);

#endif
