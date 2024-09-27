#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon) {}

std::string const & Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(std::string weapon_type)
{
	_type = weapon_type;
}
