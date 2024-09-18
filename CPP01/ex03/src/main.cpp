/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pieter <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:38:31 by pieter            #+#    #+#             */
/*   Updated: 2024/09/18 22:15:31 by pieter           ###   ########.fr       */
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
	club.setType("some other type of weapon");
	Bob.attack();

	Weapon bat("bat");
	HumanB Jim("Jim");
	Jim.setWeapon(bat);
	Jim.attack();
	bat.setType("some other type of bat");
	Jim.attack();

}

