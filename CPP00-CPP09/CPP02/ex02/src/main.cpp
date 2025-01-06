#include "../includes/Fixed.hpp"

int	main(void)
{
	Fixed			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));

    // Increment and output

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "b: " << b << std::endl;

    // Comparison tests
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;

    // Arithmetic operations
    Fixed c = a + b;
    std::cout << "a + b = " << c.toFloat() << std::endl;

    c = a - b;
    std::cout << "a - b = " << c.toFloat() << std::endl;

    c = a * b;
    std::cout << "a * b = " << c.toFloat() << std::endl;

    c = a / b;
    std::cout << "a / b = " << c.toFloat() << std::endl;

    // Min and max tests
    std::cout << "Max(a, b) = " << Fixed::max(a, b).toFloat() << std::endl;
    std::cout << "Min(a, b) = " << Fixed::min(a, b).toFloat() << std::endl;

	return (0);
}
