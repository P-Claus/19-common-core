#include "../includes/Span.hpp"

int generateRandomNumber(int min, int max)
{
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(NULL)));
        seeded = true;
    }
    return min + rand() % (max - min + 1);
}

int	main(void)
{
	Span sp = Span(5);
	
	try {
		//sp.addMany();

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printContent();
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
