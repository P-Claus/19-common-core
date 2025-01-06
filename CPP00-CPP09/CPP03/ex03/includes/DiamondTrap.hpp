#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
    public:

		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::attackDamage;
		using ScavTrap::attack;


        DiamondTrap(void);
		DiamondTrap(const std::string string);
		DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();
};

#endif

