#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <ctime>
#include <algorithm>
#include <utility>

/*	ERROR HANDLING	*/
void	intError(std::string& token);
int		handle_int(std::string& string);
bool	isInteger(std::string& string);
int		exit_handler(std::string errorMessage);

/*	VECTOR HANDLING	*/
void	printVectorBefore(std::vector<int>& numbersVector);
void	handleVector(std::vector<int> &numbersVector);

/*	DEQUE HANDLING	*/
void handleDeque(std::deque<int> &numbersDeque);

template <typename T>
void	putDataInContainer(char ** argv, T& numbers)
{

	for (int i = 1; argv[i]; i++)
	{
		std::string token = argv[i];
		intError(token);
		numbers.push_back(handle_int(token));
	}
}

#endif
