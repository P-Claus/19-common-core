#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string 		_type;
	public:
		std::string const &	getType() const;
		void			setType(std::string weapon_type);
		Weapon(std::string weapon);
};

#endif
