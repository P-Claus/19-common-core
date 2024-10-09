#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	std::string string = argv[1];

	ScalarConverter::convert(string);
}
