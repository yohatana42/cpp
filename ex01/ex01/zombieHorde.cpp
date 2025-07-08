#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	int i = 0;
	Zombie *zombies = new Zombie[n];

	if (n <= 0)
		return (NULL);
	while (i < n)
	{
		zombies[i].set_name(name);
		i++;
	}
	return (zombies);
}
