#include "../includes/PmergeMe.hpp"

/*	ERROR HANDLING	*/
int	exit_handler(std::string errorMessage)
{
	std::cerr << errorMessage << std::endl;
	exit(1);
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

/*	VECTOR HANDLING	*/
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
	std::cout << "Vector after sorting: ";
	for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void groupVectorInPairs(std::vector <int> & numbersVector)
{
	for (long unsigned int i = 0; i < numbersVector.size() - 1; i += 2)
	{
		if (numbersVector[i] < numbersVector[i+1])
			std::swap(numbersVector[i], numbersVector[i + 1]);
	}
}

std::vector <int> mergeVectorHalves(std::vector<int> leftHalf, std::vector<int> rightHalf)
{
	std::vector<int> sortedNumbers;
	size_t i = 0, j = 0;

	while (i < leftHalf.size() && j < rightHalf.size())
	{
		if (leftHalf[i] <= rightHalf[j])
		{
			sortedNumbers.push_back(leftHalf[i]);
			sortedNumbers.push_back(leftHalf[i + 1]);
			i += 2;
		}
		else
		{
			sortedNumbers.push_back(rightHalf[j]);
			sortedNumbers.push_back(rightHalf[j + 1]);
			j += 2;
		}
	}

	while (i < leftHalf.size()) {
		sortedNumbers.push_back(leftHalf[i]);
		sortedNumbers.push_back(leftHalf[i + 1]);
		i += 2;
	}
	while (j < rightHalf.size()) {
		sortedNumbers.push_back(rightHalf[j]);
		sortedNumbers.push_back(rightHalf[j + 1]);
		j += 2;
	}

	return (sortedNumbers);
}

void sortVector(std::vector<int> &numbersVector)
{
    if (numbersVector.size() <= 2)
        return;

    size_t length = numbersVector.size() / 2;
    size_t middle = length / 2;

    std::vector<int> leftHalf(numbersVector.begin(), numbersVector.begin() + 2 * middle);
    std::vector<int> rightHalf(numbersVector.begin() + 2 * middle, numbersVector.end());

    sortVector(leftHalf);
    sortVector(rightHalf);

    numbersVector = mergeVectorHalves(leftHalf, rightHalf);
}

void handleVectorStruggler(std::vector<int> &numbersVector, int struggler)
{
	std::vector<int>::iterator iter = std::lower_bound(numbersVector.begin(), numbersVector.end(), struggler);
	numbersVector.insert(iter, struggler);
}

void vectorFordJohnsonSort(std::vector <int> &numbersVector)
{
	std::vector <int> mainChain;
	std::vector <int> pendingChain;

	for (long unsigned int i = 0; i < numbersVector.size(); i += 2)
	{
		mainChain.push_back(numbersVector.at(i));
		pendingChain.push_back((numbersVector.at(i + 1)));
	}

	mainChain.insert(mainChain.begin(), pendingChain.at(0));
	pendingChain.erase(pendingChain.begin());

	int jacobStahl[17];
	jacobStahl[0] = 0;
	jacobStahl[1] = 1;
	jacobStahl[2] = 1;
	for (int i = 3; i < 17; i++)
		jacobStahl[i] = jacobStahl[i - 1] + (2 * jacobStahl[i - 2]);

	for (long unsigned int i = 3; !pendingChain.empty(); i++)
	{
		int amountOfPushes = jacobStahl[i] - jacobStahl[i - 1];
		if (amountOfPushes > static_cast<int>(pendingChain.size()))
			amountOfPushes = static_cast<int>(pendingChain.size());
		int	pendingpos = amountOfPushes - 1;

		for (int j = 0; j < amountOfPushes; j++)
		{
		   std::vector<int>::iterator iter = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[pendingpos]);
			mainChain.insert(iter, pendingChain[pendingpos]);
			pendingChain.erase(pendingChain.begin() + pendingpos);
			pendingpos--;
		}
	}
	numbersVector = mainChain;
}

void handleVector(std::vector<int> &numbersVector)
{
	groupVectorInPairs(numbersVector);
	if (numbersVector.size() % 2 != 0)
	{
		int leftOver = numbersVector.back();
		numbersVector.pop_back();
		sortVector(numbersVector);
		vectorFordJohnsonSort(numbersVector);
		handleVectorStruggler(numbersVector, leftOver);
	}
	else
	{
		sortVector(numbersVector);
		vectorFordJohnsonSort(numbersVector);
	}
	printVector(numbersVector);
}

/*	DEQUE HANDLING	*/
void	printDeque(std::deque<int>& numbersDeque)
{
	std::deque<int>::iterator	it;

	it = numbersDeque.begin();
	std::cout << "Deque after sorting: ";
	for (std::deque<int>::iterator it = numbersDeque.begin(); it != numbersDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void groupDequeInPairs(std::deque <int> & numbersDeque)
{
	for (long unsigned int i = 0; i < numbersDeque.size() - 1; i += 2)
	{
		if (numbersDeque[i] < numbersDeque[i+1])
			std::swap(numbersDeque[i], numbersDeque[i + 1]);
	}
}

std::deque <int> mergeDequeHalves(std::deque<int> leftHalf, std::deque<int> rightHalf)
{
	std::deque<int> sortedNumbers;
	size_t i = 0, j = 0;

	while (i < leftHalf.size() && j < rightHalf.size())
	{
		if (leftHalf[i] <= rightHalf[j])
		{
			sortedNumbers.push_back(leftHalf[i]);
			sortedNumbers.push_back(leftHalf[i + 1]);
			i += 2;
		}
		else
		{
			sortedNumbers.push_back(rightHalf[j]);
			sortedNumbers.push_back(rightHalf[j + 1]);
			j += 2;
		}
	}
	while (i < leftHalf.size()) {
		sortedNumbers.push_back(leftHalf[i]);
		sortedNumbers.push_back(leftHalf[i + 1]);
		i += 2;
	}
	while (j < rightHalf.size()) {
		sortedNumbers.push_back(rightHalf[j]);
		sortedNumbers.push_back(rightHalf[j + 1]);
		j += 2;
	}

	return (sortedNumbers);
}

void sortDeque(std::deque<int> &numbersDeque)
{
    if (numbersDeque.size() <= 2)
        return;

    size_t length = numbersDeque.size() / 2;
    size_t middle = length / 2;

    std::deque<int> leftHalf(numbersDeque.begin(), numbersDeque.begin() + 2 * middle);
    std::deque<int> rightHalf(numbersDeque.begin() + 2 * middle, numbersDeque.end());

    sortDeque(leftHalf);
    sortDeque(rightHalf);

    numbersDeque = mergeDequeHalves(leftHalf, rightHalf);
}

void handleDequeStruggler(std::deque<int> &numbersDeque, int struggler)
{
	std::deque<int>::iterator iter = std::lower_bound(numbersDeque.begin(), numbersDeque.end(), struggler);
	numbersDeque.insert(iter, struggler);
}

void dequeFordJohnsonSort(std::deque <int> &numbersDeque)
{
	std::deque <int> mainChain;
	std::deque <int> pendingChain;

	for (long unsigned int i = 0; i < numbersDeque.size(); i += 2)
	{
		mainChain.push_back(numbersDeque.at(i));
		pendingChain.push_back((numbersDeque.at(i + 1)));
	}

	mainChain.insert(mainChain.begin(), pendingChain.at(0));
	pendingChain.erase(pendingChain.begin());

	int jacobStahl[17];
	jacobStahl[0] = 0;
	jacobStahl[1] = 1;
	jacobStahl[2] = 1;
	for (int i = 3; i < 17; i++)
		jacobStahl[i] = jacobStahl[i - 1] + (2 * jacobStahl[i - 2]);

	//This is where the magic happens
	for (long unsigned int i = 3; !pendingChain.empty(); i++)
	{
		int amountOfPushes = jacobStahl[i] - jacobStahl[i - 1];
		if (amountOfPushes > static_cast<int>(pendingChain.size()))
			amountOfPushes = static_cast<int>(pendingChain.size());
		int	pendingpos = amountOfPushes - 1;

		for (int j = 0; j < amountOfPushes; j++)
		{
		   std::deque<int>::iterator iter = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[pendingpos]);
			mainChain.insert(iter, pendingChain[pendingpos]);
			pendingChain.erase(pendingChain.begin() + pendingpos);
			pendingpos--;
		}
	}
	numbersDeque = mainChain;
}

void handleDeque(std::deque<int> &numbersDeque)
{
	groupDequeInPairs(numbersDeque);
	if (numbersDeque.size() % 2 != 0)
	{
		int leftOver = numbersDeque.back();
		numbersDeque.pop_back();
		sortDeque(numbersDeque);
		dequeFordJohnsonSort(numbersDeque);
		handleDequeStruggler(numbersDeque, leftOver);
	}
	else
	{
		sortDeque(numbersDeque);
		dequeFordJohnsonSort(numbersDeque);
	}
	printDeque(numbersDeque);
}
