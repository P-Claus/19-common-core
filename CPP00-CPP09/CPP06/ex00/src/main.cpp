#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string string = argv[1];

		ScalarConverter::convert(string);
	}
	else
		std::cout << "Failed to do a conversion. You can only give one argument (a char, int, float or double)" << std::endl;
}
