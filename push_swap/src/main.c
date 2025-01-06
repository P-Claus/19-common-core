/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:43:31 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/04 14:08:21 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || check_for_errors(argv))
		return (1);
	else
		insert_multiple_end(argv, &a);
	if (argc == 2)
	{
		remove_all_nodes(&a);
		return (0);
	}
	if (argc == 3)
		sort_two(&a);
	if (argc == 4)
		sort_three(&a);
	if (argc == 5)
		sort_four(&a, &b);
	if (argc == 6)
		sort_five(&a, &b);
	else if (argc > 6)
		sort_many(&a, &b);
	remove_all_nodes(&a);
}
