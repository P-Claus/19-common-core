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

template <typename T>
void insertElement(T& sortedList, int element)
{
	typename T::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), element);
    sortedList.insert(it, element);
}

template <typename T>
void mergeSortedData(T& smallerList, T& largerList, T& sortedVector)
{
    sortedVector = smallerList;
    for (typename T::iterator it = largerList.begin(); it != largerList.end(); ++it)
        insertElement(sortedVector, *it);
}

template <typename T>
void sort(T& numbers)
{
    int length = numbers.size();
    if (length <= 1) return;

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
    sort(smallerElements);

    T sortedResult;

    mergeSortedData(smallerElements, largerElements, sortedResult);

    numbers = sortedResult;
}

#endif
