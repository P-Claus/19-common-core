#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_handler("Please provide as argument a string that contains a list of positive integers");

	std::string givenString = argv[1];  

	std::vector<int>	numbersVector;
	std::deque<int>		numbersDeque;

	struct timespec start, end;

	/*	Sort vector	*/
	clock_gettime(CLOCK_REALTIME, &start);

	putDataInContainer(givenString, numbersVector);
	printVectorBefore(numbersVector);
	sort(numbersVector);
	printVector(numbersVector);

	clock_gettime(CLOCK_REALTIME, &end);
	double duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	std::cout << "Sorting a vector of [" << numbersVector.size() << "] elements took " << duration << " seconds." << std::endl;

	/*	Sort deque	*/
	clock_gettime(CLOCK_REALTIME, &start);

	putDataInContainer(givenString, numbersDeque);
	sort(numbersDeque);
	//printDeque(numbersDeque);

	clock_gettime(CLOCK_REALTIME, &end);
	duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	std::cout << "Sorting a deque of [" << numbersDeque.size() << "] elements took " << duration << " seconds." << std::endl;
}
