#include "../includes/ScavTrap.hpp"

int	main(void)
{
//	ClapTrap	clapclap("CLAP");
	ScavTrap	test("TEST");

	//clapclap.attack("clap");
	//clapclap.attack("clap");
	//clapclap.attack("clap");
	//clapclap.attack("clap");

	test.attack("victim");
	test.attack("victim");
	test.attack("victim");
	test.attack("victim");

	test.takeDamage(30);
	test.takeDamage(100);

	test.beRepaired(30);
	test.beRepaired(7);

	test.guardGate();


	//clapclap.takeDamage(3);
	//clapclap.takeDamage(6);

	//clapclap.beRepaired(2);
	//clapclap.beRepaired(4);
}
