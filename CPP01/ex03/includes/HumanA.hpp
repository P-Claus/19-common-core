#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon const &		_wpn;
		std::string 		_name;
	public:
		void 			attack();
		HumanA(std::string p_name, Weapon & weapon);
		~HumanA();
};

#endif
