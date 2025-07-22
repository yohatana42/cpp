# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
    FragTrap player("player");
	FragTrap enemy("enemy");

    std::cout << "player hp :" << player.getHP() << std::endl;
	std::cout << "enemy hp :" << enemy.getHP() << std::endl;
    player.attack(&enemy);
	enemy.attack(&player);
    std::cout << "player hp :" << player.getHP() << std::endl;
	std::cout << "enemy hp :" << enemy.getHP() << std::endl;
	player.attack(&enemy);
    enemy.beRepaired(1);
    std::cout << "player hp :" << player.getHP() << std::endl;
    std::cout << "enemy hp :" << enemy.getHP() << std::endl;
	for (int i=0; i < 5; i++)
		player.attack(&enemy);
	std::cout << "player hp :" << player.getHP() << std::endl;
    std::cout << "enemy hp :" << enemy.getHP() << std::endl;
    return (0);
}
