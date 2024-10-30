/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:07 by michalkcb         #+#    #+#             */
/*   Updated: 2024/10/30 19:48:23 by mbany            ###   ########.fr       */
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
void	ft_error(void);
int		check_duplicates(int *nbr, int len);
int		create_new_node_for_top(t_stack *stack, int value);
void	index_assigmenent(t_stack *stack);
int		check_sorted_in_stack(t_stack *stack);

//push_swap_utils2
int		ft_word_count2(char const *str, char c);
long	ft_atol(char *str);
void	free_split(char **split);
int		ft_check_int_range(long num);
void	check_number_in_str(char **parts_str, int *nbrs, int i);

//push_swap_utils3
void	split_atol_free(char *str, int *nbrs);
int		allocate_memory_for_stacks(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack *stack);
int		ft_check_forbidden_char(char *str);
int		fill_nbrs_array(int argc, char **argv, int *nbrs);

//push_swap_utils4
void	initialize_nbrs_array(int argc, char **argv, int **nbrs, int *nbr_nbrs);

//sort_for_3
void	sort_3_nbr(t_stack **stack, int a, int b, int c);
void	sort_3_nbr_on_stack(t_stack **stack);
void	sort_small_stack(t_stack *stack);

//sort_for_4_to_9
int		find_index_for_min_value(t_stack *stack);
void	push_min_value_to_b(t_stack *stack_a, t_stack *stack_b);
void	sort_for_4_to_9(t_stack *stack_a, t_stack *stack_b);

//sort_for_more
int		calcule_group_size_with_sqrt(int size);
void	chunk_sort1(t_stack *stack_a, t_stack *stack_b, int size_a);
int		count_r(t_node *stack, int nbr);
void	r_stack_b(t_stack *stack_b, int size_b, int rb_count, int rrb_count);
void	chunk_sort2(t_stack *stack_a, t_stack *stack_b, int size_b);

//push_swap
int		init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);

#endif
