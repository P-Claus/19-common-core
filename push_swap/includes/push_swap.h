/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:22:57 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/26 13:29:34 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					destination;
	int					cheapest_to_push;
	bool				above_median;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_node;

typedef struct s_function_params
{
	int					iter_a;
	int					iter_b;
	int					index_a;
	int					index_b;
}						t_fp;

int						main(int argc, char **argv);

/*	ERROR CHECKING	*/
int						check_for_errors(char **argv);
int						error_check_integer(char **argv);
int						error_check_duplicates(char **argv);
int						error_check_for_int(char **argv);
int						error_check_empty_string(char **argv);
int						check_if_list_is_sorted(t_node **head);

/*	ACTIONS	*/
void					sa(t_node *head_a);
void					sb(t_node *head_b);
void					ss(t_node *head_a, t_node *head_b);
void					pa(t_node **head_a, t_node **head_b);
void					pb(t_node **head_a, t_node **head_b);
void					ra(t_node **head);
void					rb(t_node **head);
void					rr(t_node **head_a, t_node **head_b);
void					rra(t_node **head);
void					rrb(t_node **head);
void					rrr(t_node **head_a, t_node **head_b);

/*	ALGORITHM FUNCTIONS	*/
void					sort_two(t_node **head);
void					sort_three(t_node **head);
void					sort_three_reverse(t_node **head);
void					sort_four(t_node **head_a, t_node **head_b);
void					sort_five(t_node **head_a, t_node **head_b);
void					sort_five_final_sort(t_node **head);
void					sort_five_fourth_int(t_node **head_a, t_node **head_b,
							int destination);
void					sort_five_fifth_int(t_node **head_a, t_node **head_b,
							int destination);
void					sort_many(t_node **head_a, t_node **head_b);
void					sort_many_push_to_b(t_node **head_a, t_node **head_b,
							int cheapest_steps_to_push);

/*	UTILS	*/
void					tail_to_head(t_node **tail);
void					head_to_tail(t_node **head);
int						is_valid_int(char *str);
int						check_destination(t_node **head, int new_value);
int						check_destination_reverse(t_node **head, int new_value,
							int count);
int						find_lowest_int(t_node **head_a);
int						return_lowest_int(t_node **head_a);
int						return_highest_int(t_node **head);
long					ft_atoi_long(const char *str);
int						count_steps_to_be_in_position(t_node **head_a,
							t_node **head_b);
void					update_median(t_node **head, int count);
int						count_nodes(t_node **head);
int						count_nodes_and_update_index(t_node **head);
void					set_median(t_node **head, int iter, int count,
							int median);
void					update_cheapest_to_push_member(t_node **head_a,
							t_node **head_b, int count_a, int count_b);
void					put_highest_int_at_head(t_node **head);
void					rotate_b_to_be_in_position(t_node **head_a,
							t_node **head_b, int *index_b, int *iter_b);
void					insert_end(t_node **head, int data);
void					insert_multiple_end(char **argv, t_node **head);
void					remove_all_nodes(t_node **head);

#endif
