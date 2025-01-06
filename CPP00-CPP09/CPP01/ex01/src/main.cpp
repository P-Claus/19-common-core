#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie* horde = zombieHorde(9, "Charlie");

	for (int i = 0; i < 9; i++)
	{
		std::cout << "#" << i + 1 << ":";
		horde[i].announce();
	}
	delete [] horde;
	horde = NULL;
}
