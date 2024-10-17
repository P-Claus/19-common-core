#include "../includes/easyfind.hpp"

int	main(void)
{
	std::vector<int> intVector;

	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);
	intVector.push_back(5);
	intVector.push_back(6);
	intVector.push_back(7);


	easyfind(intVector, 4);	
	easyfind(intVector, 9);	
	easyfind(intVector, 0);	
	easyfind(intVector, 1);	
}
