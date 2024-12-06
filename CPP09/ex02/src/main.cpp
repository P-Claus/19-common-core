#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit_handler("Please provide as argument a string that contains a list of positive integers");

	std::vector<int>	numbersVector;
	std::deque<int>		numbersDeque;

	struct timespec start, end;

	clock_gettime(CLOCK_REALTIME, &start);
	
	//I need to pass the argv and add the numbers from index 1 to the end
	putDataInContainer(argv, numbersVector);
	printVectorBefore(numbersVector);
	sort(numbersVector);
	printVector(numbersVector);

	clock_gettime(CLOCK_REALTIME, &end);
	double duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e3;
	std::cout << "Sorting a vector of [" << numbersVector.size() << "] elements took " << duration << " milliseconds." << std::endl;

	clock_gettime(CLOCK_REALTIME, &start);

	putDataInContainer(argv, numbersDeque);
	sort(numbersDeque);
	//printDeque(numbersDeque);

	clock_gettime(CLOCK_REALTIME, &end);
	duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e3;
	std::cout << "Sorting a deque of [" << numbersDeque.size() << "] elements took " << duration << " milliseconds." << std::endl;
}
