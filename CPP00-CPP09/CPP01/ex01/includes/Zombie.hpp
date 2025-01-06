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
		void	init(std::string zombieName);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
