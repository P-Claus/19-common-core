#include "../includes/PmergeMe.hpp"

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

void sortVector(std::vector & numbersVector)
{

    int length = numbersVector.size();
    if (length <= 1) return;

	std::cout << "The length of the list is: " << length << std::endl;

	int half = length /2;
	std::cout << "The half is: " << half << std::endl;

	T leftPart;
	T rightPart;

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
