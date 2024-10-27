#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>

bool	isInteger(std::string& string);
int		handle_int(std::string& string);
void	putInStack(std::stack<int>&numbers, int token);
void	doCalculation(std::stack<int>& numbers, std::string token);
void	operatorCheckEnd(std::string string);
void	determineOperatorOrInteger(std::string& token, bool& isInt, bool& isOp);
void	useStackAndCalculate(std::string& token, std::stack<int>& numbers, bool& isInt, bool& isOp);
int		exit_handler(std::string error_message);

#endif
