#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit_handler("Please provide as argument a string that contains a list of positive integers");

	std::vector<int>	numbersVector;
	std::deque<int>		numbersDeque;

	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
	
	putDataInContainer(argv, numbersVector);
	printVectorBefore(numbersVector);
	handleVector(numbersVector);

	clock_gettime(CLOCK_REALTIME, &end);
	double duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
	std::cout << "Sorting a vector of [" << numbersVector.size() << "] elements took " << duration << " microseconds." << std::endl;
	std::cout << std::endl;

	clock_gettime(CLOCK_REALTIME, &start);

	putDataInContainer(argv, numbersDeque);
	handleDeque(numbersDeque);

	clock_gettime(CLOCK_REALTIME, &end);
	duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
	std::cout << "Sorting a deque of [" << numbersDeque.size() << "] elements took " << duration << " microseconds." << std::endl;
	std::cout << std::endl;
}
