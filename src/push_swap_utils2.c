/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:33:02 by mbany             #+#    #+#             */
/*   Updated: 2024/11/02 19:51:32 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		alloc_mem_4_stack(t_stack **stack_a, t_stack **stack_b)
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
void	index_assigmenent(t_stack *stack)
{
	t_node *current;
	t_node *checker;
	int index;
	
	current = stack->top;
	while (current)
	{
		index = 0;
		checker = stack->top;
		while (checker)
		{
			if (checker->value < current->value)
				index++;
			checker = checker->next;
		}
		current->index = index;
		current = current->next;
	}
}
/*function for creating number of index node by value from the smallest number,
not sort!,
when checker find small value then current have high index +1*/
int		check_sorted_in_stack(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	if (stack->top == NULL || stack->top->next == NULL)
		return (1);
	if (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
