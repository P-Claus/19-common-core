#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	std::string const *wpn;
	std::string name;

	public:
		void attack();
		HumanB(std::string p_name);
		~HumanB();
		void setWeapon(Weapon weapon);
};

#endif
