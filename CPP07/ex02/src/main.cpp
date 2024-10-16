#include "../includes/Array.hpp"

/*	EXCEPTIONS	*/
template<typename T>
const char* Array<T>::indexTooHighException::what() const throw()
{
	return ("The index you have entered is out of range (too high)");
}

template<typename T>
const char* Array<T>::indexTooLowException::what() const throw()
{
	return ("The index you have entered is out of range (too low)");
}

int	main(void)
{
	//Array<char> newChar;
	//Array<char> newCharParam(7);

	Array<int> newInt;
	Array<int> newIntParam(10);

	try
	{
		std::cout << newInt[2] << std::endl;
		newInt.printContent();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl;

	try
	{
		std::cout << newIntParam[-8] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl;
	//copy assignment
	try
	{
		newIntParam.setData(0, 111);
		newIntParam.setData(1, 112);
		newIntParam.setData(2, 113);
		newIntParam.setData(3, 114);
		newIntParam.setData(4, 115);
		newIntParam.setData(5, 116);
		newIntParam.setData(6, 117);
		newIntParam.setData(7, 118);
		newIntParam.setData(8, 119);
		newIntParam.setData(9, 120);
		newIntParam.printContent();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl;

	Array<int> copyIntParam(newIntParam);

	copyIntParam.printContent();
	try
	{
		copyIntParam.setData(0, 1);
		copyIntParam.setData(1, 2);
		copyIntParam.setData(2, 3);
		copyIntParam.setData(3, 4);
		copyIntParam.setData(4, 5);
		copyIntParam.setData(5, 6);
		copyIntParam.setData(6, 7);
		copyIntParam.setData(7, 8);
		copyIntParam.setData(8, 9);
		copyIntParam.setData(9, 0);
		copyIntParam.printContent();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	newIntParam.printContent();


	std::cout << "-------------------------------------------" << std::endl;

	Array<int> assignmentArray(10);

	assignmentArray = copyIntParam;

	assignmentArray.printContent();
	try
	{
		assignmentArray.setData(0, 77);
		assignmentArray.setData(1, 78);
		assignmentArray.setData(2, 79);
		assignmentArray.setData(3, 80);
		assignmentArray.setData(4, 81);
		assignmentArray.setData(5, 82);
		assignmentArray.setData(6, 83);
		assignmentArray.setData(7, 84);
		assignmentArray.setData(8, 85);
		assignmentArray.setData(9, 86);
		assignmentArray.printContent();
		copyIntParam.printContent();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}



}

