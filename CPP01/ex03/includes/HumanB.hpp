#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	Weapon const *wpn;
	std::string name;

	public:
		void attack();
		HumanB(std::string p_name);
		~HumanB();
		void setWeapon(Weapon & weapon);
};

#endif
