/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efret <efret@student.19.be>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:00:46 by efret             #+#    #+#             */
/*   Updated: 2024/06/18 14:16:04 by efret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_pow(int base, int pow)
{
	if (!pow)
		return (1);
	if (pow < 0)
		return (0);
	return (base * ft_pow(base, pow - 1));
}