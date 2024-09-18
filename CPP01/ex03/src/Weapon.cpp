#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
	std::cout << "The weapon is created: " << type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "The weapon is destroyed: " << type << std::endl;
}

std::string const & Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(std::string weapon_type)
{
	type = weapon_type;
}
