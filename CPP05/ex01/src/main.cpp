#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Form newForm;
		std::cout << newForm << std::endl;

		Form secondForm("secondForm", 10, 10);
		std::cout << secondForm << std::endl;

		Form thirdForm("thirdForm", 33, 17);
		std::cout << thirdForm << std::endl;

		Form fourthForm(thirdForm);
		std::cout << fourthForm << std::endl;

		Bureaucrat	William("William", 20);
		std::cout << William << std::endl;

		thirdForm.beSigned(William);
		std::cout << thirdForm << std::endl;

		Bureaucrat Bob("Bob", 10);
		std::cout << Bob << std::endl;

		secondForm.beSigned(Bob);
		std::cout << secondForm << std::endl;
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
