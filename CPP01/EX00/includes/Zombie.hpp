#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "main.hpp"

class Zombie
{
	std::string name;

	public:
		void	announce();
		Zombie(std::string zombie_name);
		~Zombie();
};

#endif
