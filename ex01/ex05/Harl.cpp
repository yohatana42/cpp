
#include "Harl.hpp"

Harl::Harl() {}

void Harl::complain(std::string level)
{
    this->_func[0] = &Harl::debug;
    this->_func[1] = &Harl::info;
    this->_func[2] = &Harl::warning;
    this->_func[3] = &Harl::error;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4;i++)
    {
        if (levels[i] == level)
        {
            (this->*_func[i])();
            return ;
        }
    }
}

void Harl::debug()
{
    std::cout << "debug" << std::endl;
}

void Harl::info()
{
    std::cout << "info" << std::endl;
}

void Harl::warning()
{
    std::cout << "warning" << std::endl;
}

void Harl::error()
{
    std::cout << "error" << std::endl;
}