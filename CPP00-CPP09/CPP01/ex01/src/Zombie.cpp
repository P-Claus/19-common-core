#include "../includes/Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << _name << " died..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::init(std::string zombieName)
{
	_name = zombieName;
}

