#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon) {}

std::string const & Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(std::string weaponType)
{
	_type = weaponType;
}
