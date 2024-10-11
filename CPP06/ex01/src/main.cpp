#include "../includes/Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	dataObj;

	dataObj.nb = 19;

	std::cout << "The original address of the data object is: " << &dataObj << std::endl;

	uintptr_t uintPtr = Serializer::serialize(&dataObj);

	std::cout << "The uint after serialize is: " << uintPtr << std::endl;
	std::cout << "The address of int after serialize is: " << &uintPtr << std::endl;

	Data *dataReturnObj = Serializer::deserialize(uintPtr);	

	std::cout << "The address after deserialize is: " << dataReturnObj << std::endl;
}
