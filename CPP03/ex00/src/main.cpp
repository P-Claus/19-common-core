#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapclap("CLAP");
	clapclap.attack("clap");
	clapclap.attack("clap");
	clapclap.attack("clap");
	clapclap.attack("clap");

	clapclap.takeDamage(3);
	clapclap.takeDamage(6);

	clapclap.beRepaired(2);
	clapclap.beRepaired(4);
}
