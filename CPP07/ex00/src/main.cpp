#include "../includes/whatever.hpp"

int	main(void)
{
	int a = 2;
	int	b = 3;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap<int>(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

	std::cout << "-------------------------" << std::endl;

	std::string c = "mister";
	std::string d = "robot";

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap<std::string>(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

	std::cout << "-------------------------" << std::endl;

	char	e = 'e';
	char	f = 'f';

	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	::swap<char>(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min<char>( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max<char>( e, f ) << std::endl;

	std::cout << "-------------------------" << std::endl;

	float	g = 19.19f;
	float	h = 42.42f;

	std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
	::swap<float>(g, h);
	std::cout << "After swap: g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min<float>( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max<float>( g, h ) << std::endl;
}
