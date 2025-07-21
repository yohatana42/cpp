#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(5, "aaaaaa");
	if (!zombies)
	{
		std::cout << "zombieHorde failed" << std::endl;
		return (1);
	}
	for (int i = 0; i < 5;i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
