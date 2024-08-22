/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:48:56 by pclaus            #+#    #+#             */
/*   Updated: 2024/06/11 21:55:40 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int	main(int argc, char ** argv)
{
	int	iter (0);
	int	counter (1);

	if (argc == 1)
		std::cout << ("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
	else
	{
		while (counter < argc)
		{
			while (argv[counter][iter] != '\0')
				std::cout << (char)toupper(argv[counter][iter++]);
			std::cout << " ";
			iter = 0;
			counter++;
		}
		std::cout << std::endl;
	}
	return (0);
}
