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
	/*	FUNCTIONALITY WITH COMPLEX TYPES -> CREATING AN ARRAY OF STRUCTS	*/
	std::cout << " ------------------------ " << std::endl;
	std::cout << "| Testing a complex type |" << std::endl;
	std::cout << " ------------------------ " << std::endl;
	std::cout << std::endl;

	Array<complexType> complexArray(2);

	std::cout << std::endl;
	std::cout << "-- Before setting any data --" << std::endl;
	std::cout << std::endl;

	complexType data1 = {3, "Jeff"};
	complexType data2 = {7, "Bob"};

	std::cout << "Element 0: " << complexArray[0].name << ", " << complexArray[0].nb << std::endl;
    std::cout << "Element 1: " << complexArray[1].name << ", " << complexArray[1].nb << std::endl;

	complexArray.setData(0 , data1);
	complexArray.setData(1 , data2);

	std::cout << std::endl;
	std::cout << "-- After setting the data --" << std::endl;
	std::cout << std::endl;

	std::cout << "Element 0: " << complexArray[0].name << ", " << complexArray[0].nb << std::endl;
    std::cout << "Element 1: " << complexArray[1].name << ", " << complexArray[1].nb << std::endl;


	/*	FUNCTIONALITY WITH SIMPLE TYPES -> CREATING AN ARRAY OF INTEGERS	*/

	std::cout << std::endl;
	std::cout << " ----------------------------- " << std::endl;
	std::cout << "| Testing simple integer type |" << std::endl;
	std::cout << " ----------------------------- " << std::endl;
	std::cout << std::endl;

	Array<int> emptyIntArray;

	std::cout << std::endl;
	std::cout << "-- Accessing an index in the empty integer array --" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << emptyIntArray[2] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<int> intArray(10);

	std::cout << std::endl;
	std::cout << "-- Accessing an index in the integer array --" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "The value at index 8 before setting it is: " << intArray.getData(8) << std::endl;
		intArray.setData(8, 19);
		std::cout << "The value at index 8 after setting it is: " << intArray.getData(8) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-- Accessing a negative index in the integer array --" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << intArray[-8] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	/*	COPY CONSTRUCTOR FUNCTIONALITY	*/

	std::cout << std::endl;
	std::cout << " ----------------------------------------- " << std::endl;
	std::cout << "| Setting the values of the integer array |" << std::endl;
	std::cout << " ----------------------------------------- " << std::endl;
	std::cout << std::endl;


	intArray.setData(0, 111);
	intArray.setData(1, 112);
	intArray.setData(2, 113);
	intArray.setData(3, 114);
	intArray.setData(4, 115);
	intArray.setData(5, 116);
	intArray.setData(6, 117);
	intArray.setData(7, 118);
	intArray.setData(8, 119);
	intArray.setData(9, 120);

	for (int i = 0; i < intArray.size(); i++)
		std::cout << "[" << i << "] -> " << intArray.getData(i) << std::endl; 

	std::cout << std::endl;
	std::cout << " ------------------------------ " << std::endl;
	std::cout << "| Testing the copy constructor |" << std::endl;
	std::cout << " ------------------------------ " << std::endl;
	std::cout << std::endl;

	Array<int> copyIntArray(intArray);

	std::cout << std::endl;
	std::cout << "-- after copying and before changing the values --" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < copyIntArray.size(); i++)
		std::cout << "[" << i << "] -> " << copyIntArray.getData(i) << std::endl; 

	copyIntArray.setData(0, 1);
	copyIntArray.setData(1, 2);
	copyIntArray.setData(2, 3);
	copyIntArray.setData(3, 4);
	copyIntArray.setData(4, 5);
	copyIntArray.setData(5, 6);
	copyIntArray.setData(6, 7);
	copyIntArray.setData(7, 8);
	copyIntArray.setData(8, 9);
	copyIntArray.setData(9, 0);

	std::cout << std::endl;
	std::cout << "-- after changing the values --" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < copyIntArray.size(); i++)
		std::cout << "[" << i << "] -> " << copyIntArray.getData(i) << std::endl; 

	/*	ASSIGNMENT CONSTRUCTOR FUNCTIONALITY	*/

	std::cout << std::endl;
	std::cout << " ------------------------------------ " << std::endl;
	std::cout << "| Testing the assignment constructor |" << std::endl;
	std::cout << " ------------------------------------ " << std::endl;
	std::cout << std::endl;

	Array<int> assignmentIntArray(20);
	assignmentIntArray = intArray;

	std::cout << std::endl;
	std::cout << "-- after assignment and before changing the values --" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < assignmentIntArray.size(); i++)
		std::cout << "[" << i << "] -> " << assignmentIntArray.getData(i) << std::endl; 

	assignmentIntArray.setData(0, 1);
	assignmentIntArray.setData(1, 2);
	assignmentIntArray.setData(2, 3);
	assignmentIntArray.setData(3, 4);
	assignmentIntArray.setData(4, 5);
	assignmentIntArray.setData(5, 6);
	assignmentIntArray.setData(6, 7);
	assignmentIntArray.setData(7, 8);
	assignmentIntArray.setData(8, 9);
	assignmentIntArray.setData(9, 0);

	std::cout << std::endl;
	std::cout << "-- after changing the values --" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < assignmentIntArray.size(); i++)
		std::cout << "[" << i << "] -> " << assignmentIntArray.getData(i) << std::endl; 

/*


	//Array<char> newChar;
	//Array<char> newCharParam(7);


	std::cout << "-------------------------------------------" << std::endl;
	//copy assignment


	copyIntArray.printContent();
	try
	{
		copyIntArray.printContent();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	intArray.printContent();


	std::cout << "-------------------------------------------" << std::endl;

	Array<int> assignmentArray(10);

	assignmentArray = copyIntArray;

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
		copyIntArray.printContent();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
*/
}

