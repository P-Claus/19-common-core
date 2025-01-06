#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename P>
void	printValue(P elem)
{
	std::cout << "The value is: " << elem << std::endl;
}

template<typename T, typename U, typename F>
void iter(T* arrayAddress, U arrayLength, F func)
{
	//std::cout << "The address of the array is: " << static_cast<void*>(arrayAddress) << std::endl;
	//std::cout << "The length of the array is: " << arrayLength << std::endl;
	for (U i = 0; i < arrayLength; i++)
		func(arrayAddress[i]);
}

#endif
