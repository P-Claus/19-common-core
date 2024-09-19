#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
}

std::string const & Weapon::getType(void) const
{
	return (type);
}

void Weapon::setType(std::string weapon_type)
{
	type = weapon_type;
}
