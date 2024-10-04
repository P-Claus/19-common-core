#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string pName, Weapon & weapon) : _wpn(weapon) , _name(pName) 
{
	std::cout << "HumanA is born..." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA died..." << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << this->_wpn.getType() <<std::endl;
}


