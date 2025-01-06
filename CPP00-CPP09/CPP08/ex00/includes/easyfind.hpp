#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void	easyfind(T intContainer, int nb)
{
	typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), nb);	

	if (it != intContainer.end())
		std::cout << "The integer was found: " << *it << std::endl;
	else
		std::cout << "The integer was not found in the list: " << *it << std::endl;
}

#endif
