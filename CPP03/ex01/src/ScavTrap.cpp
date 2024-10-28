#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "Default ScavTrap constructor is called" << std::endl;
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Default ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
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

ScavTrap::ScavTrap(const std::string string)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
	_name = string;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"; 
		_energyPoints--;
		std::cout << " || EP left: " << _energyPoints << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " has no energy or hitpoints left!" << std::endl;;
	}
}

void	ScavTrap::guardGate(void)const
{
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode!" << std::endl;
}
