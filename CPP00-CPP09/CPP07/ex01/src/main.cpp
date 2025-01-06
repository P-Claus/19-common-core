#include "../includes/iter.hpp"

int	main(void)
{
	//array of integers
	int	array[10];

	for (int i = 0; i < 10; i++)
		array[i] = i + 100;

	iter<int, int, void(int)>(array, 10, printValue);


	//array of floats
	std::cout << "-----------------------" << std::endl;
	float	arrayFlt[10];

	for (int i = 0; i < 10; i++)
		arrayFlt[i] = i + 19.19;

	iter<float, int, void(float)>(arrayFlt, 10, printValue);

	//array of chars
	std::cout << "-----------------------" << std::endl;
	char	arrayChar[10];

	for (int i = 0; i < 10; i++)
		arrayChar[i] = 'a' + i;
	iter<char, int, void(char)>(arrayChar, 10, printValue);
	
}

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/
