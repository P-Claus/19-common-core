#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string p_name, Weapon & weapon) : weapon(weapon.getType()) 
{
	name = p_name;
	(void)p_name;

}

HumanA::~HumanA()
{
	std::cout << "HumanA died..." << std::endl;
}

void HumanA::attack()
{
	std::cout << name << " attacks with " << weapon << std::endl;
}


