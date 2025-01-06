#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie* Billy = newZombie("Billy"); 
	randomChump("Joel");
	delete(Billy);
}
