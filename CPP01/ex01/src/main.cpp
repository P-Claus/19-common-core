#include "../includes/Zombie.hpp"

void	Zombie::init(std::string zombie_name)
{
	name = zombie_name;
}

Zombie*    zombieHorde( int N, std::string name )
{

	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		horde[i].init(name);

	return (horde);
	
}

int	main(void)
{
	Zombie* horde = zombieHorde(5, "Charlie");

	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}

	delete [] horde;
	horde = NULL;
}
