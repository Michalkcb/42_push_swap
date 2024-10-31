/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:41 by mbany             #+#    #+#             */
/*   Updated: 2024/10/31 19:58:23 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_nbrs_array(int ac, char **av, int **nbrs, int *nbr_nbrs)
{
	if (ac == 2)
		*nbr_nbrs = ft_word_count(av[1], ' ');
	else
		*nbr_nbrs = ac - 1;
	if (ac == 1)
		exit (1);
	*nbr_nbrs = (int *)malloc(sizeof(int) * (*nbr_nbrs));
	if(!(*nbrs))
		ft_error();
	if (fill_nbrs_array(ac, av, *nbrs) == -1)
	{
		free(*nbrs);
		ft_error();
	}
	if (check_duplicates(*nbrs, *nbr_nbrs))
	{
		free(*nbrs);
		ft_error();
	}
}

int		ft_word_count(char const *s, char c)
{
	int count;
	int in_nbr;

	in_nbr = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_nbr == 0)
		{
			count++;
			in_nbr = 1;
		}
		else if (*s == c)
			in_nbr = 0;
		s++;
	}
	return (count);
}

void ft_error(void)
{
	write(2,"Error\n",6);
	exit(1);
}

int		alloc_mem_4_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a =(t_stack *)malloc(sizeof(t_stack));
	*stack_b =(t_stack *)malloc(sizeof(t_stack));
	if (*stack_a == NULL || *stack_b == NULL)
		return (-1);
	(*stack_a)->top = NULL;
	(*stack_b)->top = NULL;
	(*stack_a)->size = 0;
	(*stack_b)->size = 0;
	return (0);
}

int		create_new_node_4_top(t_stack *stack, int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if(new_node == NULL)
		return (-1);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (0);
}

/* function for create new node on the top in stack when we use operation push
new_node->index = -1 because stack now is not sort and the first index is 0
so new node top have -1*/
