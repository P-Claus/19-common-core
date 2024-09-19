#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string p_name, Weapon & weapon) : wpn(weapon) 
{
	std::cout << "HumanA is born..." << std::endl;
	name = p_name;
}

HumanA::~HumanA()
{
	std::cout << "HumanA died..." << std::endl;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << this->wpn.getType() <<std::endl;
}


