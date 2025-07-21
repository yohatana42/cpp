#ifndef ZOMBIE_H
 #define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
	public:
		void announce();
		Zombie(std::string name);
		Zombie();
		~Zombie();
	private:
		std::string _name;
};

	Zombie *newZombie(std::string name);
	void randomChump(std::string name);

#endif
