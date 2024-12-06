#include "../includes/RPN.hpp"

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

void	putInStack(std::stack<int>&numbers, int token)
{
	numbers.push(token);	
}

void	doCalculation(std::stack<int>& numbers, std::string token)
{
	int		last = numbers.top();
	numbers.pop();
	int		secondToLast = numbers.top();
	numbers.pop();
	int		result = 0;

	if (token == "+")
		result = secondToLast + last;
	else if (token == "-")
		result = secondToLast - last;
	else if (token == "*")
		result = secondToLast * last;
	else if (token == "/")
		result = secondToLast / last;
	
	putInStack(numbers, result);
}

void	operatorCheckEnd(std::string string)
{
	if (string[string.size() - 1] != '+' && string[string.size() -1] != '-' && string[string.size() - 1] != '*' && string[string.size() - 1] != '/')
		exit_handler("Error");
}

void	determineOperatorOrInteger(std::string& token, bool& isInt, bool& isOp)
{
	isInt = false;
	isOp = false;

	if (token == "+" || token == "-" || token == "*" || token == "/")
		isOp = true;
	else if (isInteger(token) == true)
	{
		if (handle_int(token) >= 0 && handle_int(token) <= 9)
			isInt = true;
		else
			exit_handler("Error: numbers need to be between 0 and 9");
	}
	else	
		exit_handler("Error");
	
}

void	useStackAndCalculate(std::string& token, std::stack<int>& numbers, bool& isInt, bool& isOp)
{
	if (isInt == true)
		putInStack(numbers, handle_int(token));
	else if (isOp == true)
		doCalculation(numbers, token);
}
