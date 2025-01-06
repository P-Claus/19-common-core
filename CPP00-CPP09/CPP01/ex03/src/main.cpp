/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pieter <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:38:31 by pieter            #+#    #+#             */
/*   Updated: 2024/10/04 13:36:13 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int	main(void)
{
	Weapon dds = Weapon("dragon dagger");
	
	HumanA Bob("Bob", dds);
	Bob.attack();
	dds.setType("dragon scimitar");
	Bob.attack();

	Weapon longsword = Weapon("dragon longsword");

	HumanB Jim("Jim");
	Jim.attack();
	Jim.setWeapon(longsword);
	Jim.attack();
	longsword.setType("abyssal whip");
	Jim.attack();

}

