/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:07 by michalkcb         #+#    #+#             */
/*   Updated: 2024/11/02 19:54:23 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct  s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

//operations_swap_push
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//operations_rotate
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

//operations_rrotate
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//push_swap_utils
void	init_nbrs_array(int ac, char **av, int **nbrs, int *nbr_nbrs);
int		ft_word_count(char const *s, char c);
void	ft_error(void);
int		fill_nbrs_array(int argc, char **argv, int *nbrs);
int		check_duplicates(int *nbr, int len);

//push_swap_utils2
int		alloc_mem_4_stack(t_stack **stack_a, t_stack **stack_b);
int		create_new_node_4_top(t_stack *stack, int value);
void	index_assigmenent(t_stack *stack);
int		check_sorted_in_stack(t_stack *stack);
void	free_stack(t_stack *stack);

//push_swap_utils3
int		ft_check_forbidden_char(char *s);
long	ft_atol(char *s);
int		ft_check_int_range(long num);
void	split_atol_free(char *s, int *nbrs);
void	check_number_in_s(char **parts_str, int *nbrs, int i);


//push_swap_utils4
void	free_split(char **split);

//sort_for_3
void	sort_3_nbr(t_stack **stack, int a, int b, int c);
void	sort_3_nbr_on_stack(t_stack **stack);
void	sort_3_stack(t_stack *stack);

//sort_4_to_9
int		find_index_for_min_value(t_stack *stack);
void	push_min_value_to_b(t_stack *stack_a, t_stack *stack_b);
void	sort_4_to_9(t_stack *stack_a, t_stack *stack_b);

//sort_for_more
void	sort1(t_stack *stack_a, t_stack *stack_b, int size_a);
int		calcule_group_size_with_sqrt(int size);
void	sort2(t_stack *stack_a, t_stack *stack_b, int size_b);
int		count_r(t_node *stack, int nbr);
void	r_stack_b(t_stack *stack_b, int size_b, int rb_count, int rrb_count);

//push_swap
int		init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);

#endif
