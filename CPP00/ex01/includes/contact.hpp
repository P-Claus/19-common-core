#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include <cstring>

class Contact
{
	std::string strings[5];

	public:
		void	truncate_string(std::string *string);
//		void	print_contacts(std::string string);

//		void	print_single_contact();
		void 	fill_contact(std::string input_data[]);
	
	Contact(void)
	{
		std::cout << "This is the contact constructor" << std::endl;
	};

	~Contact(void)
	{
		std::cout << "This is the contact destructor" << std::endl;
	};
};

#endif
