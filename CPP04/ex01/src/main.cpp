#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int	main(void)
{
	/*
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
	*/
	
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



	/*


	//	DECLARE ARRAY AND FILL WITH OBJECTS	 
	Animal	*animal_arr[4];
	for (int i = 0; i < 2; i++)
		animal_arr[i] = new Dog();

	for (int i = 2; i < 4; i++)
		animal_arr[i] = new Cat();

	for (int i = 0; i < 4; i++)
		delete animal_arr[i];
*/

	/*    
	Cat firstCat;
    firstCat.getAddr();                   // Address of first cat's brain
    
    Cat secondCat;
    secondCat = firstCat;                 // Use assignment operator to copy the first cat into the second
    secondCat.getAddr();


	delete originalCat;
	*/
}
