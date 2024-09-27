#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		void	announce();
		Zombie(std::string zombie_name);
		~Zombie();
};

Zombie*	newZombie(std::string name); 
void	randomChump(std::string name);

#endif
