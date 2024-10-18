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

class Span
{
	private:
		std::vector<int>		_intSpan;
		size_t					_capacity;
		Span();
	public:
		//constructors
		Span(size_t N);

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
