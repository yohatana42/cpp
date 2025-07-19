# include "ClapTrap.hpp"

int main()
{
    ClapTrap player("player");

    std::cout << "hp :" << player.getHP() << std::endl;
    player.attack("enemy");
    player.takeDamage(3);
    std::cout << "hp :" << player.getHP() << std::endl;
    player.beRepaired(1);
    std::cout << "hp :" << player.getHP() << std::endl;
    return (0);
}