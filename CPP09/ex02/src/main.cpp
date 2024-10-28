#include "../includes/PmergeMe.hpp"

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

void	intError(int nb)
{
	if (nb < 0 || nb > INT_MAX)
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

		intError(handle_int(token));
		numbersVector.push_back(handle_int(token));
		std::cout << "The last element in the vector is: " << numbersVector.back() << std::endl;
		std::cout << "The size of the vector is: " << numbersVector.size() << std::endl;

		givenString.erase(0, pos + delim.length());
	}
	token = givenString.substr(0, 1);
	numbersVector.push_back(handle_int(token));
	std::cout << "The last element in the vector is: " << numbersVector.back() << std::endl;
	std::cout << "The size of the vector is: " << numbersVector.size() << std::endl;
}

void	putDataInDeque(std::string givenString, std::deque<int>& numbersDeque)
{
	std::string 	delim = " ";  
	size_t 			pos = 0;  
	std::string 	token;  
	
	while ((pos = givenString.find(delim)) != std::string::npos)  
	{
		token = givenString.substr(0, pos);

		intError(handle_int(token));
		numbersDeque.push_back(handle_int(token));
		std::cout << "The last element in the deque is: " << numbersDeque.back() << std::endl;
		std::cout << "The size of the deque is: " << numbersDeque.size() << std::endl;

		givenString.erase(0, pos + delim.length());
	}
	token = givenString.substr(0, 1);
	numbersDeque.push_back(handle_int(token));
	std::cout << "The last element in the deque is: " << numbersDeque.back() << std::endl;
	std::cout << "The size of the deque is: " << numbersDeque.size() << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_handler("Please provide as argument a string that contains a list of positive integers");

	std::string givenString = argv[1];  

	std::vector<int>	numbersVector;
	std::deque<int>		numbersDeque;

	putDataInVector(givenString, numbersVector);
	putDataInDeque(givenString, numbersDeque);
	std::cout << "The size of the vector from the main function is: " << numbersVector.size() << std::endl;
	std::cout << "The size of the deque from the main function is: " << numbersDeque.size() << std::endl;
}
