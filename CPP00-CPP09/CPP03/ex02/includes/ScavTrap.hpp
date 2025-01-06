#ifndef SCAVTRAP_HPP 
# define SCAVTRAP_HPP
# include "./ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
    public:
		//constructor
        ScavTrap(void);

		//parameter constructor
		ScavTrap(const std::string string);

		//copy constructor
        ScavTrap(const ScavTrap &other);

		//copy assignment overload
        ScavTrap &operator=(const ScavTrap &other);

		//destructor
        ~ScavTrap();

		//misc.
		void	attack(const std::string& target);
		void	guardGate();
};

#endif

