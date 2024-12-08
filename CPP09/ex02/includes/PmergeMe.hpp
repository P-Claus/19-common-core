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

void	intError(std::string& token);
int		handle_int(std::string& string);
void	printVectorBefore(std::vector<int>& numbersVector);
void	printVector(std::vector<int>& numbersVector);
void	printDeque(std::deque<int>& numbersDeque);
bool	isInteger(std::string& string);
int		exit_handler(std::string errorMessage);
void	 sortVector(std::vector<int> &numbers);
void 	groupInPairs(std::vector <int> & numbers);
void workWithMainChain(std::vector <int> &numbersVector);
void handleStruggler(std::vector<int> &numbersVector, int struggler);

template <typename T>
void insertElement(T& sortedList, int element)
{
	typename T::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), element);
    sortedList.insert(it, element);
}

template <typename T>
void mergeSortedData(T& smallerList, T& largerList, T& sortedContainer)
{
    sortedContainer = smallerList;
    for (typename T::iterator it = largerList.begin(); it != largerList.end(); ++it)
        insertElement(sortedContainer, *it);
}

/*
template <typename T>
void sort(T& numbers)
{
    int length = numbers.size();
    if (length <= 1) return;

	std::cout << "The length of the list is: " << length << std::endl;

	int half = length /2;
	std::cout << "The half is: " << half << std::endl;

	T leftPart;
	T rightPart;




    T smallerElements;
	T largerElements;

    for (int i = 0; i < length; i += 2)
	{
        if (i + 1 < length)
		{
            if (numbers[i] < numbers[i + 1])
			{
                smallerElements.push_back(numbers[i]);
                largerElements.push_back(numbers[i + 1]);
            } else {
                smallerElements.push_back(numbers[i + 1]);
                largerElements.push_back(numbers[i]);
            }
        } else {
            smallerElements.push_back(numbers[i]);
        }
    }
	std::cout << "The large elements is: " << largerElements.front() << std::endl;
	std::cout << "The small elements is: " << smallerElements.front() << std::endl;
    sort(smallerElements);

    T sortedResult;

    mergeSortedData(smallerElements, largerElements, sortedResult);

	numbers = sortedResult;
}
*/

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
