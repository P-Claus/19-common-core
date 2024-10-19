#include "../includes/Span.hpp"

/*	CONSTRUCTORS	*/
Span::Span()
{
}

Span::Span(size_t N): _capacity(N)
{
	std::cout << "The parameter constructor has been called" << std::endl;;
	_intSpan.reserve(N);
}

/*	COPY CONSTRUCTOR	*/
Span::Span(const Span& other): _intSpan(other._intSpan), _capacity(other._capacity)
{
	std::cout << "The copy constructor has been called" << std::endl;
}

/*	COPY ASSIGNMENT OVERLOAD	*/
Span& Span::operator=(const Span& rhs)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &rhs)
	{
		_intSpan = rhs._intSpan;
		_capacity = rhs._capacity;
	}
	return (*this);
}

/*	DESTRUCTOR	*/
Span::~Span()
{
	std::cout << "The destructor has been called" << std::endl;
}

/*	MISC.	*/
void	Span::addNumber(int nb)
{
	if (_intSpan.size() < _capacity)
		_intSpan.push_back(nb);
	else
		throw std::out_of_range("You cannot add any more numbers to the vector");
}

void	Span::printContent(void)
{
	std::cout << "The vector has a max size of: " << _capacity << std::endl;
	for (size_t i = 0; i < _intSpan.size(); i++)
		std::cout << _intSpan[i] << std::endl;
}

int		Span::shortestSpan()
{
	if (_intSpan.size() < 2)
		throw std::invalid_argument("The vector needs to contain at least two integers");
	else
	{
		std::vector<int> differences(_intSpan.size());  
		for (size_t i = 1; i < _intSpan.size(); ++i)
            differences[i] = std::abs(_intSpan[i] - _intSpan[i - 1]);
		std::vector<int>::iterator it = min_element(differences.begin() + 1, differences.end());
		return (*it);
	}
}

int		Span::longestSpan()
{
	if (_intSpan.size() < 2)
		throw std::invalid_argument("The vector needs to contain at least two integers");
	else
	{
		std::vector<int> differences(_intSpan.size());  
		for (size_t i = 1; i < _intSpan.size(); ++i)
            differences[i] = std::abs(_intSpan[i] - _intSpan[i - 1]);
		std::vector<int>::iterator it = max_element(differences.begin() + 1, differences.end());
		return (*it);
	}
}

void	Span::addMany()
{
	std::vector<int>::iterator	it;
	_intSpan.resize(_capacity);
	for (it = _intSpan.begin(); it != _intSpan.end(); it++)
		*it = generateRandomNumber(0, 100000);
}
