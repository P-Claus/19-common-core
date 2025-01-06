#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		void	print_contact_header();
		void	display_contact_header();
		void	display_contacts(PhoneBook *phonebook);
		int	add_contact(Contact *contact, int *counter);

	public:
		void	print_header();
		void	display_prompt(std::string *answer);
		int	evaluate_answer(PhoneBook *phonebook, std::string answer, int *index, int *counter);
};

#endif
