#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "Default FragTrap constructor is called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Default FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    (void) other;
    return ;
}

FragTrap::FragTrap(const std::string string)
{
    std::cout << "FragTrap string constructor called" << std::endl;
	name = string;;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

void	FragTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"; 
		energyPoints--;
		std::cout << " || EP left: " << energyPoints << std::endl;
	}
	else {
		std::cout << "FragTrap " << name << " has no energy or hitpoints left!" << std::endl;;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says: 'HIGH FIVE'" << std::endl;
}
