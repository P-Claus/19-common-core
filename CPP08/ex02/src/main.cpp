#include "../includes/MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "The top of the stack is: " << mstack.top() << std::endl;

	mstack.pop();

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

}
