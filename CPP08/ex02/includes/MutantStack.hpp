#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <string>

template<typename T>
class MutantStack : public std::stack<T, std::vector<T> >
{
	public:
	    typedef typename std::vector<T>::iterator iterator;

		//constructor
		MutantStack()
		{
			std::cout << "Default constructor has been called" << std::endl;
		}

		//copy constructor
		MutantStack(const MutantStack& other)
		{
			std::cout << "The copy constructor has been called" << std::endl;
			(void)other;
		}

		//copy assignment operator overload
		MutantStack& operator=(const MutantStack& rhs)
		{
			std::cout << "The copy assignment overload function has been called" << std::endl;
			(void)rhs;
			return (*this);
		}

		//destructor
		~MutantStack()
		{
			std::cout << "The destructor has been called" << std::endl;
		}

		//iterator functions
		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
};

#endif
