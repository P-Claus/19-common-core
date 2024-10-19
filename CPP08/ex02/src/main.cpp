#include "../includes/MutantStack.hpp"

int	main(void)
{
	std::cout << " --------------------- " << std::endl;
	std::cout << "| Tests with integers |" << std::endl;
	std::cout << " --------------------- " << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack;

	if (mstack.empty())
		std::cout << "The mutantstack is empty" << std::endl;
	else
		std::cout << "The mutantstack is not empty" << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "The top of the stack is: " << mstack.top() << std::endl;

	mstack.pop();

	if (mstack.empty())
		std::cout << "The mutantstack is empty" << std::endl;
	else
		std::cout << "The mutantstack is not empty" << std::endl;

	std::cout << "The size of the stack is: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(727);
	mstack.push(19);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	std::cout << "it is: " << *it << std::endl;

	--it;
	std::cout << "it is: " << *it << std::endl;

	while (it != ite)
	{
    	std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::cout << " -------------------- " << std::endl;
	std::cout << "| Tests with strings |" << std::endl;
	std::cout << " -------------------- " << std::endl;
	std::cout << std::endl;

	MutantStack<std::string> stringMutantStack;

	stringMutantStack.push("java");
	stringMutantStack.push("javascript");
	stringMutantStack.push("c");
	stringMutantStack.push("cpp");
	stringMutantStack.push("python");

	MutantStack<std::string>::iterator itStr = stringMutantStack.begin();
	MutantStack<std::string>::iterator iteStr = stringMutantStack.end();

	while (itStr != iteStr)
	{
    	std::cout << *itStr << std::endl;
		++itStr;
	}
}
