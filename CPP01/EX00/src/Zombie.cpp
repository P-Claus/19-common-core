#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
	name = zombie_name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " died..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

