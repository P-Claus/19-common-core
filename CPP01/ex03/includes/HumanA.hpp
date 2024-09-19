#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	Weapon const & wpn;
	std::string name;

	public:
		void attack();
		HumanA(std::string p_name, Weapon & weapon);
		~HumanA();
};

#endif
