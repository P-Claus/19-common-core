#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int	main(void)
{
	std::cout << std::endl;;
	std::cout << "TESTS DEEP COPY FUNCTIONALITY" << std::endl;
	std::cout << std::endl;;

	//	TESTS TO SHOW DEEP COPY FUNCTIONALITY
	const Cat *originalCat = new Cat();
    originalCat->getAddr();
	originalCat->makeSound();

    const Cat *copiedCat = new Cat(*originalCat);
    copiedCat->getAddr();
	copiedCat->makeSound();

	delete originalCat;
	delete copiedCat;

	const Dog *originalDog = new Dog();
	originalDog->getAddr();
	originalDog->makeSound();

	const Dog *copiedDog = new Dog(*originalDog);
	copiedDog->getAddr();
	copiedDog->makeSound();

	delete originalDog;
	delete copiedDog;

	std::cout << std::endl;;
	std::cout << "TESTS FOR ASSIGMNENT OPERATOR FUNCTIONALITY" << std::endl;
	std::cout << std::endl;;
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	//	TESTS TO SHOW ASSIGNMENT OPERATOR FUNCTIONALITY
	Cat *firstCat = new Cat();
	firstCat->getAddr();
	firstCat->makeSound();
	firstCat->getType();

	Cat *secondCat = new Cat();
	*secondCat = *firstCat;
	secondCat->getAddr();
	secondCat->makeSound();
	secondCat->getType();

	delete firstCat;
	delete secondCat;

	Dog *firstDog = new Dog();
	firstDog->getAddr();
	firstDog->makeSound();
	firstDog->getType();

	Dog *secondDog = new Dog();
	*secondDog = *firstDog;
	secondDog->getAddr();
	secondDog->makeSound();
	secondDog->getType();

	delete firstDog;
	delete secondDog;

}
