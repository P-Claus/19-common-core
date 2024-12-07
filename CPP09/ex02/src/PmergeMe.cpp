#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <utility>

int	exit_handler(std::string errorMessage)
{
	std::cerr << errorMessage << std::endl;
	exit(1);
}

void	printVectorBefore(std::vector<int>& numbersVector)
{
	std::vector<int>::iterator	it;

	it = numbersVector.begin();
	std::cout << "Before sorting: ";
	for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void	printVector(std::vector<int>& numbersVector)
{
	std::vector<int>::iterator	it;

	it = numbersVector.begin();
	std::cout << "After sorting: ";
	for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*
void	printDeque(std::deque<int>& numbersDeque)
{
	std::deque<int>::iterator	it;

	it = numbersDeque.begin();
	std::cout << "Deque after sorting: ";
	for (std::deque<int>::iterator it = numbersDeque.begin(); it != numbersDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
*/

std::vector <std::pair <int, int> > mergePairs(std::vector <std::pair <int, int> > &sortedLeftHalf, std::vector <std::pair <int, int> > & sortedRightHalf)
{
	std::vector <std::pair <int, int> > mergedPairs;
	long unsigned int i = 0, j = 0;

	while (i < sortedLeftHalf.size() && j < sortedRightHalf.size())
	{
		if (sortedLeftHalf[i].first <= sortedRightHalf[j].first)
		{
			mergedPairs.push_back(sortedLeftHalf[i]);
			std::cout << "The nb is: " << sortedLeftHalf[i].first << std::endl;
			i++;
		}
		else
		{
			mergedPairs.push_back(sortedRightHalf[j]);
			std::cout << "The nb is: " << sortedRightHalf[j].first << std::endl;
			j++;
		}
	}

	while (i < sortedLeftHalf.size())
	{
		mergedPairs.push_back(sortedLeftHalf[i]);
		std::cout << "The nb is: " << sortedLeftHalf[i].first << std::endl;
		i++;
	}

	while (j < sortedRightHalf.size())
	{
		mergedPairs.push_back(sortedRightHalf[j]);
		std::cout << "The nb is: " << sortedRightHalf[j].first << std::endl;
		j++;
	}
	return (mergedPairs);
}

std::vector <std::pair <int, int> > recursivePairSort(std::vector <std::pair <int, int> > & pairs)
{
	std::vector <std::pair <int, int> > sortedPairs;

	if (pairs.size() <= 1)
		return (pairs);

	int half = pairs.size() / 2;

	std::vector <std::pair <int, int> > leftHalf(pairs.begin(), pairs.begin() + half);
	std::vector <std::pair <int, int> > rightHalf(pairs.begin() + half, pairs.begin() + half);

	
	std::vector <std::pair <int, int> > sortedLeftHalf = recursivePairSort(leftHalf);
	std::vector <std::pair <int, int> > sortedRightHalf = recursivePairSort(rightHalf);

	return (mergePairs(sortedLeftHalf, sortedRightHalf));
}

std::vector <int> & sortVector(std::vector<int> & numbersVector)
{

    int length = numbersVector.size();
    if (length <= 1)
		return (numbersVector);

	std::cout << "The length of the list is: " << length << std::endl;

	int half = length /2;
	std::cout << "The half is: " << half << std::endl;

	std::vector <std::pair <int, int> > pairVector;

	for (int i = 0; i < length; i += 2)
		pairVector.push_back(std::make_pair(numbersVector.at(i), numbersVector.at(i + 1)));

	pairVector = recursivePairSort(pairVector); 
	
	return (numbersVector);

	//std::vector <int>::iterator it = numbersVector.begin();
/*
	//for even amount of numbers
	if (length % 2 == 0)
	{

		std::cout << "The size of the vector is: " << pairVector.size() << std::endl;

		for (long unsigned int i = 0; i < pairVector.size() ; i++)
		{
			std::cout << "First element of pair: " << pairVector[i].first << " || Second element of pair: " << pairVector[i].second << std::endl;
		}

		//sort the elements in each pair from H -> L
		for (long unsigned int i = 0; i < pairVector.size() ; i++)
		{
			if (pairVector[i].first < pairVector[i].second)
			{
				int temp = pairVector[i].first;
				pairVector[i].first = pairVector[i].second;
				pairVector[i].second = temp;
			}

		}
	
	

	}
	else
	{
		for (int i = 0; i < length - 1; i += 2)
			pairVector.push_back(std::make_pair(numbersVector.at(i), numbersVector.at(i + 1)));

		pairVector.push_back(std::make_pair(numbersVector.back()));

		std::cout << "The size of the vector is: " << pairVector.size() << std::endl;

		for (long unsigned int i = 0; i < pairVector.size() ; i++)
		{
			std::cout << "First element of pair: " << pairVector[i].first << " || Second element of pair: " << pairVector[i].second << std::endl;
		}

		//sort the elements in each pair from H -> L
		for (long unsigned int i = 0; i < pairVector.size() ; i++)
		{
			if (pairVector[i].first < pairVector[i].second)
			{
				int temp = pairVector[i].first;
				pairVector[i].first = pairVector[i].second;
				pairVector[i].second = temp;
			}

		}
			
	}

	for (long unsigned int i = 0; i < pairVector.size() ; i++)
	{
		std::cout << "First element of pair: " << pairVector[i].first << " || Second element of pair: " << pairVector[i].second << std::endl;
	}
	*/
	}

	

bool	isInteger(std::string& string)
{
	std::stringstream 	ss;
	int 				integer;

	ss << string;
	ss >> integer;

	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);
}

int		handle_int(std::string& string)
{
	std::stringstream	ss;
	int					integer;

	ss << string;
	ss >> integer;

	return (integer);
}

void	intError(std::string& token)
{
	if (isInteger(token) == false)
		exit_handler("Error: numbers must be integers");
	else if (handle_int(token) < 0)
		exit_handler("Error: numbers must be positive integers");
}
