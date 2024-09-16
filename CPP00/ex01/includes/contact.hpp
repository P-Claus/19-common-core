#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

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
	
		Contact();
};

#endif
