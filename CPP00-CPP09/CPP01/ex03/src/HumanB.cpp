#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string pName) : _wpn(NULL), _name(pName)
{
	std::cout << "HumanB is born..." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB died..." << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	_wpn = &weapon;
}

void	HumanB::attack()
{
	if (this->_wpn)
		std::cout << _name << " attacks with their " << this->_wpn->getType() << std::endl;
	else
		std::cout << _name << " does not have a weapon yet!" << std::endl;
}

