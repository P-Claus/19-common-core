#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string p_name) : wpn(nullptr)
{
	std::cout << "HumanB is born..." << std::endl;
	name = p_name;
}

HumanB::~HumanB()
{
	std::cout << "HumanB died..." << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	std::cout << "The weapon is: " << weapon.getType() << std::endl;
	wpn = new std::string;
	wpn = &weapon.getType();
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << *wpn << std::endl;
}

