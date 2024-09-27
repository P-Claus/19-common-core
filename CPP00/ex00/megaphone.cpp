/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:48:56 by pclaus            #+#    #+#             */
/*   Updated: 2024/09/27 08:52:17 by pieter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char ** argv)
{
	int				iter (0);
	int				counter (1);
	std::string 	wo_args = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string		curr_arg;

	if (argc == 1)
		std::cout << wo_args << std::endl;
	else
	{
		while (counter < argc)
		{
			curr_arg = argv[counter];
			while (curr_arg[iter] != '\0')
				std::cout << (char)toupper(curr_arg[iter++]);
			std::cout << " ";
			iter = 0;
			counter++;
		}
		std::cout << std::endl;
	}
	return (0);
}
