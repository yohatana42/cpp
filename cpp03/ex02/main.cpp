# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
    FragTrap player("player");

    std::cout << "player hp :" << player.getHP() << std::endl;
    player.attack("aaa");
	player.beRepaired(2);
	std::cout << "player hp :" << player.getHP() << std::endl;
	player.takeDamage(5);
	std::cout << "player hp :" << player.getHP() << std::endl;
	player.highFivesGuys();
    return (0);
}
