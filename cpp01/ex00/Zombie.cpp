#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    this->announce();
    return;
}

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
