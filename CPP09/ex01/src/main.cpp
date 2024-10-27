#include "../includes/RPN.hpp"

int	exit_handler(std::string errorMessage)
{
	std::cout << errorMessage << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	bool			isInt;
	bool			isOp;
	std::string		givenString;
	std::stack<int>	numbers;

	if (argc != 2)
		exit_handler("Please provide a string you wish to calculate as parameter");

	givenString = argv[1];  

	operatorCheckEnd(givenString);

	std::string 	delim = " ";  
	size_t 			pos = 0;  
	std::string 	token;  
	  
	while ((pos = givenString.find(delim)) != std::string::npos)  
	{
		token = givenString.substr(0, pos);

		determineOperatorOrInteger(token, isInt, isOp);
		useStackAndCalculate(token, numbers, isInt, isOp);

		givenString.erase(0, pos + delim.length());
	}
	token = givenString.substr(0, 1);
	doCalculation(numbers, token);
	std::cout << numbers.top() << std::endl;
}
