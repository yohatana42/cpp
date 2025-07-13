
#include "Zombie.hpp"

int main()
{
	// heap
	Zombie *zombie_1 = newZombie("aaaaa");
	zombie_1->announce();
	delete zombie_1;

	// stack
	randomChump("bbbb");
	return (0);
}
