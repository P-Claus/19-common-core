#include "../includes/PmergeMe.hpp"
#include <climits>
#include <ctime>


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

void	putDataInVector(std::string givenString, std::vector<int>& numbersVector)
{
	std::string 	delim = " ";  
	size_t 			pos = 0;  
	std::string 	token;  
	
	while ((pos = givenString.find(delim)) != std::string::npos)  
	{
		token = givenString.substr(0, pos);
		intError(token);
		numbersVector.push_back(handle_int(token));
		givenString.erase(0, pos + delim.length());
	}
	token = givenString.substr(0, pos);
	intError(token);
	numbersVector.push_back(handle_int(token));
}

void	putDataInDeque(std::string givenString, std::deque<int>& numbersDeque)
{
	std::string 	delim = " ";  
	size_t 			pos = 0;  
	std::string 	token;  
	
	while ((pos = givenString.find(delim)) != std::string::npos)  
	{
		token = givenString.substr(0, pos);
		intError(token);
		numbersDeque.push_back(handle_int(token));
		givenString.erase(0, pos + delim.length());
	}
	token = givenString.substr(0, pos);
	intError(token);
	numbersDeque.push_back(handle_int(token));

}

void	mergeVector(std::vector<int>& leftVector, std::vector<int>& rightVector, std::vector<int>& numbersVector)
{
	int	leftSize = leftVector.size();
	int	rightSize = rightVector.size();

	int l = 0;
	int	r = 0;

	numbersVector.clear();

	while (l < leftSize && r < rightSize)
	{
		if (leftVector[l] < rightVector[r])
		{
			numbersVector.push_back(leftVector.at(l));
			l++;
		}
		else
		{
			numbersVector.push_back(rightVector.at(r));
			r++;
		}
	}
	while (l < leftSize)
	{
		numbersVector.push_back(leftVector.at(l));
		l++;
	}
	while (r < rightSize)
	{
		numbersVector.push_back(rightVector.at(r));
		r++;
	}
}

void	mergeSortVector(std::vector<int>& numbersVector)
{
	int	length = numbersVector.size();

	if (length <= 1)
		return ;

	int	middle = length / 2;

	std::vector<int>	leftVector;
	std::vector<int>	rightVector;

	for (int i = 0; i < length; i++)
	{
		if (i < middle)
			leftVector.push_back(numbersVector.at(i));
		else
			rightVector.push_back(numbersVector.at(i));
	}
	mergeSortVector(leftVector);
	mergeSortVector(rightVector);
	mergeVector(leftVector, rightVector, numbersVector);
}


int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_handler("Please provide as argument a string that contains a list of positive integers");

	std::string givenString = argv[1];  

	std::vector<int>	numbersVector;
	std::deque<int>		numbersDeque;

	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);


	putDataInVector(givenString, numbersVector);
	printVectorBefore(numbersVector);
	putDataInDeque(givenString, numbersDeque);
	mergeSortVector(numbersVector);
	printVector(numbersVector);

	clock_gettime(CLOCK_REALTIME, &end);

	double duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    std::cout << "someFunction() took " << duration << " seconds to execute." << std::endl;


}
