#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>

class Span
{
	private:
		std::vector<int>		_intSpan;
		size_t					_capacity;

		//default constructor
		Span();

	public:
		//parameter constructor
		Span(size_t N);

		//copy constructor
		Span(const Span& other);

		//copy assignment overload
		Span& operator=(const Span& rhs);

		//destructor
		~Span();

		//misc.
		void	addNumber(int nb);
		void	printContent(void);
		int		shortestSpan();
		int		longestSpan();
		void	addMany();
};

int	generateRandomNumber(int min, int max);

#endif
