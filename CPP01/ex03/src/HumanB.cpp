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

void	HumanB::setWeapon(Weapon & weapon)
{
	wpn = &weapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << this->wpn->getType() << std::endl;
}

