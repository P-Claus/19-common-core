#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "Default FragTrap constructor is called" << std::endl;
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Default FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
    return (*this);
}

FragTrap::FragTrap(const std::string string)
{
    std::cout << "FragTrap string constructor called" << std::endl;
	_name = string;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"; 
		_energyPoints--;
		std::cout << " || EP left: " << _energyPoints << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name << " has no energy or hitpoints left!" << std::endl;;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says: 'HIGH FIVE'" << std::endl;
}
