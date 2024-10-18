#include "../includes/Span.hpp"
#include <exception>

int generateRandomNumber(int min, int max) {
    // Seed the random number generator only once per program execution
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(NULL)));  // Seed with current time
        seeded = true;
    }

    // Generate a random number in the range [min, max]
    return min + rand() % (max - min + 1);
}

int	main(void)
{
	Span sp = Span(5);

	try {

		sp.addMany();

		sp.addNumber(6);
	//	sp.addNumber(3);
		//sp.addNumber(17);
		//sp.addNumber(9);
		//sp.addNumber(11);
		sp.printContent();
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}
