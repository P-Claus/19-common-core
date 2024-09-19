/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pieter <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:38:31 by pieter            #+#    #+#             */
/*   Updated: 2024/09/19 17:34:19 by pieter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int	main(void)
{
	Weapon club("club");
	
	HumanA Bob("Bob", club);
	Bob.attack();
	club.setType("dragon scimitar");
	Bob.attack();

	Weapon bat("bat");
	HumanB Jim("Jim");
	Jim.setWeapon(bat);
	Jim.attack();
	bat.setType("abyssal whip");
	Jim.attack();

}

