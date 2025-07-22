# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
    ScavTrap player("player");

	player.attack("enemy");
    std::cout << "player hp :" << player.getHP() << std::endl;
    player.beRepaired(1);
    std::cout << "player hp :" << player.getHP() << std::endl;
	player.guardGate();
	for (int i=0; i < 5; i++)
		player.attack("enemy");
	std::cout << "player hp :" << player.getHP() << std::endl;
    return (0);
}
