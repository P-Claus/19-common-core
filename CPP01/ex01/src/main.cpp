#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie* horde = zombieHorde(9, "Charlie");

	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	horde = NULL;
}
