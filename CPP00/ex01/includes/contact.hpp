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
	int			index;

	public:
		std::string	truncate_string(std::string *string);
		void		print_contacts();

		void		print_single_contact();
		void 		fill_contact(std::string input_data[], int new_index);
		int			check_contact_exists();
	
	Contact(void)
	{
		std::cout << "This is the contact constructor" << std::endl;
		index = 0;
		strings[0] = "";
		strings[1] = "";
		strings[2] = "";
		strings[3] = "";
		strings[4] = "";
	};

	~Contact(void)
	{
		std::cout << "This is the contact destructor" << std::endl;
	};
};

#endif
