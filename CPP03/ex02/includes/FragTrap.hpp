#ifndef FRAGTRAP_HPP 
# define FRAGTRAP_HPP
# include "./ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
    public:
		//constructor
        FragTrap(void);

		//parameter constructor
		FragTrap(const std::string string);

		//copy constructor
        FragTrap(const FragTrap &other);

		//copy assignment overload
        FragTrap &operator=(const FragTrap &other);

		//destructor
        ~FragTrap();

		//misc.
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif

