#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* kitty = new WrongCat();


	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << kitty->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	kitty->makeSound();

	delete j;
	delete i;
	delete meta;
	delete kitty;
}
