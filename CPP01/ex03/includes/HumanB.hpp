#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon const *_wpn;
		std::string _name;
	public:
		void attack();
		HumanB(std::string p_name);
		~HumanB();
		void setWeapon(Weapon & weapon);
};

#endif
