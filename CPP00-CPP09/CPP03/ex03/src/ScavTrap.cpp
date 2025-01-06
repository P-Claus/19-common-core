#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "Default ScavTrap constructor is called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Default ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    (void) other;
    return ;
}

ScavTrap::ScavTrap(const std::string string)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
	name = string;;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"; 
		energyPoints--;
		std::cout << " || EP left: " << energyPoints << std::endl;
	}
	else {
		std::cout << "ScavTrap " << name << " has no energy or hitpoints left!" << std::endl;;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in gate keeper mode!" << std::endl;
}
