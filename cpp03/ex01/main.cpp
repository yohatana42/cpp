# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
    ScavTrap player("player");
	ScavTrap enemy("enemy");

    std::cout << "hp :" << player.getHP() << std::endl;
    player.attack(&enemy);
    player.takeDamage(9);
    std::cout << "hp :" << player.getHP() << std::endl;
    player.beRepaired(1);
    std::cout << "hp :" << player.getHP() << std::endl;

    // ENERGY 0
    for (int  i = 0; i < 10; i++)
    {
        player.beRepaired(1);
    }
    std::cout << "hp :" << player.getHP() << std::endl;
    return (0);
}
