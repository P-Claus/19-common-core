#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string zombie_name) : _name(zombie_name)
{
	std::cout << "String contructor for " << _name << " has been called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " died..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

