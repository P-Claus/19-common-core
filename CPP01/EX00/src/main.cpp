#include "../includes/main.hpp"

int main(void)
{
	Zombie* Billy = newZombie("Billy"); 
	Billy->announce();
	randomChump("Joel");
	delete(Billy);

}
