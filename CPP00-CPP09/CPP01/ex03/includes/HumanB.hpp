#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon const 	*_wpn;
		std::string 	_name;
	public:
		HumanB(std::string pName);
		~HumanB();
		void 		attack();
		void 		setWeapon(Weapon & weapon);
};

#endif
