#include "../includes/main.hpp"

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
