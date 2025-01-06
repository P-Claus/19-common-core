/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:42:31 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 20:54:59 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node *head_a)
{
	int	temp;

	if (head_a == NULL)
		return ;
	temp = head_a->value;
	head_a->value = head_a->next->value;
	head_a->next->value = temp;
	ft_printf("sa\n");
}
