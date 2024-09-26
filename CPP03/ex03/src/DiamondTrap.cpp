#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor in DiamondTrap has been called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Default destructor in DiamondTrap has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string string)
{
	std::cout << "String constructor in DiamondTrap has been called" << std::endl;
	name = string;
	std::cout << "HP is : " << FragTrap::hitPoints << std::endl;
	std::cout << "EP is : " << ScavTrap::energyPoints << std::endl;
	std::cout << "Damage is : " << FragTrap::attackDamage << std::endl;
	attack("Bill");
	std::cout << "My name is: " << name << " and ClapTrap's name is: " << ClapTrap::name << std::endl;
}
