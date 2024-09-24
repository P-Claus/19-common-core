#include "../includes/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
    return ;
}

ClapTrap::ClapTrap(const std::string string)
{
    std::cout << "String constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 6;
	attackDamage = 3;
	name = string;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"; 
		energyPoints--;
		std::cout << " || EP left: " << energyPoints << std::endl;
	}
	else {
		std::cout << "ClapTrap " << name << " has no energy or hitpoints left!" << std::endl;;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
		std::cout << "ClapTrap " << name << " is hit, losing " << amount << " hitpoints!";
		
		hitPoints -= amount;
		std::cout << " || HP left: " << hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself and gains " << amount << " hitpoint(s).";
		hitPoints += amount;
		energyPoints--;
		std::cout << " || HP left: " << hitPoints << " || EP left: " << energyPoints<< std::endl;
	}
	else {
		std::cout << "ClapTrap " << name << " has no energy or hitpoints left!" << std::endl;;
	}

}
