/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/09/14 09:46:23 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

void Contact::truncate_string(std::string *string)
{
		if ((*string).length() > 10)
		{
			(*string).resize (9);
			*string = *string + ".";
		}

}


void Contact::fill_contact(std::string input_data[])
{
	strings[1] = input_data[1];
	strings[2] = input_data[2];
	strings[3] = input_data[3];
	strings[4] = input_data[4];
	strings[5] = input_data[5];

	std::cout << strings[0] << std::endl;
	std::cout << strings[1] << std::endl;
	std::cout << strings[2] << std::endl;
	std::cout << strings[3] << std::endl;
	std::cout << strings[4] << std::endl;
	std::cout << strings[5] << std::endl;
}

/*
void Contact::print_contacts()
{
	truncate_string(&firstName);
	truncate_string(&lastName);
	truncate_string(&nickName);
	truncate_string(&phoneNumber);
	truncate_string(&secret);

	std::cout << std::setw(10) << index << "|" <<
	std::setw(10) << firstName << "|" << std::setw(10) <<
	lastName << "|" << std::setw(10) << nickName << std::endl;
}

void	Contact::print_single_contact()
{
	std::cout << "Firstname: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Their darkest secret: " << secret << std::endl;
}
*/
