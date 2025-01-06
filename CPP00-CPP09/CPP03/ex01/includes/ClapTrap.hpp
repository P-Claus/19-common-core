#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
    public:
		//default constructor
        ClapTrap(void);

		//parameter constructor
		ClapTrap(const std::string string);

		//copy constructor
        ClapTrap(const ClapTrap& other);

		//copy assignment operator overload
        ClapTrap &operator=(const ClapTrap &other);

		//destructor
        ~ClapTrap();

		//misc.
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

