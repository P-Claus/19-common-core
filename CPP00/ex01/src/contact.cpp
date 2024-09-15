/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/09/15 18:49:43 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

std::string	Contact::truncate_string(std::string *string)
{
	std::string	trunc_string;

	if ((*string).length() > 10)
	{
		trunc_string = *string;
		trunc_string.resize (9);
		trunc_string = trunc_string + ".";
		return (trunc_string);
	}
	else 
		return (*string);
}


void Contact::fill_contact(std::string input_data[], int new_index)
{
	index = new_index;;
	strings[0] = input_data[0];
	strings[1] = input_data[1];
	strings[2] = input_data[2];
	strings[3] = input_data[3];
	strings[4] = input_data[4];
}

void Contact::print_contacts()
{
	std::string fname = truncate_string(&strings[0]);
	std::string lname = truncate_string(&strings[1]);
	std::string nname = truncate_string(&strings[2]);

	if (index != 0)
	{
		std::cout << std::setw(10) << index << "|" <<
		std::setw(10) << fname << "|" << std::setw(10) <<
		lname << "|" << std::setw(10) << nname << std::endl;
	}
}
void	Contact::print_single_contact()
{
	std::cout << "Firstname: " << strings[0] << std::endl;
	std::cout << "Last name: " << strings[1] << std::endl;
	std::cout << "Nickname: " << strings[2] << std::endl;
	std::cout << "Phone number: " << strings[3] << std::endl;
	std::cout << "Their darkest secret: " << strings[4] << std::endl;
}

int	Contact::check_contact_exists()
{
	if (index != 0)
		return (0);
	else
		return (1);		
}
