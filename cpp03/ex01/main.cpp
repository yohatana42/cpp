# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
    ScavTrap player("player");

	player.attack("enemy");
    std::cout << "player hp :" << player.getHP() << std::endl;
    player.beRepaired(1);
    std::cout << "player hp :" << player.getHP() << std::endl;
	player.takeDamage(2);
	std::cout << "player hp :" << player.getHP() << std::endl;
	player.guardGate();
	std::cout << "player hp :" << player.getHP() << std::endl;
    return (0);
}
