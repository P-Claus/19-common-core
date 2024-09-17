#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


class Zombie
{
	std::string name;

	public:
		void	announce();
		void	init(std::string zombie_name);
		~Zombie();
};

Zombie*	newZombie(); 

#endif
