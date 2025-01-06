#include "../includes/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const std::string string): _name(string), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Claptrap String constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
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

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "Default ClapTrap destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"; 
		_energyPoints--;
		std::cout << " || EP left: " << _energyPoints << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " has no energy or hitpoints left!" << std::endl;;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	left;

	if (_hitPoints > 0)
	{
		if (_hitPoints - amount < 0 || _hitPoints - amount > 10)
		{
			left = amount - _hitPoints;
			left = amount - left;
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " is hit, losing " << left << " hitpoint(s)!";
		std::cout << " || HP left: " << _hitPoints << std::endl;
			return ;
		}
		else
			_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " is hit, losing " << amount << " hitpoint(s)!";
		std::cout << " || HP left: " << _hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no hitpoints left!" << std::endl;;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself and gains " << amount << " hitpoint(s).";
		_hitPoints += amount;
		_energyPoints--;
		std::cout << " || HP left: " << _hitPoints << " || EP left: " << _energyPoints<< std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " has no energy or hitpoints left!" << std::endl;;
	}

}
