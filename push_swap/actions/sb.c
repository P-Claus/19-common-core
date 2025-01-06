/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:25:12 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 20:55:07 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_node *head_b)
{
	int	temp;

	if (head_b == NULL)
		return ;
	temp = head_b->value;
	head_b->value = head_b->next->value;
	head_b->next->value = temp;
	ft_printf("sb\n");
}
