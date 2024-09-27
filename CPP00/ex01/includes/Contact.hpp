#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
	private:
		int		index;
		std::string	strings[5];
		std::string	truncate_string(std::string *string);
	public:
		Contact();
		void 		fill_contact(std::string input_data[], int new_index);
		void		print_contacts();
		void		print_single_contact();
		int		check_contact_exists();
};

#endif
