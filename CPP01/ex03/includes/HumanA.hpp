#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	std::string const & weapon;
	std::string name;

	public:
		void attack();
		HumanA(std::string p_name, Weapon & weapon);
		~HumanA();
};

#endif
