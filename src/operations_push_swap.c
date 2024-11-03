/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:34:20 by mbany             #+#    #+#             */
/*   Updated: 2024/11/03 14:36:10 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int		temp;
	t_node	*first;
	t_node	*second;

	first = stack_a->top;
	second = stack_a->top->next;
	if (stack_a->top != NULL && stack_a->top->next != NULL)
	{
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int		temp;
	t_node	*first;
	t_node	*second;

	first = stack_b->top;
	second = stack_b->top->next;
	if (stack_b->top != NULL && stack_b->top->next != NULL)
	{
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	write(1, "sb\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	temp = stack_b->top;
	if (stack_b->top == NULL)
		return ;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_b->size--;
	stack_a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	temp = stack_a->top;
	if (stack_a->top != NULL)
	{
		stack_a->top = stack_a->top->next;
		temp->next = stack_b->top;
		stack_b->top = temp;
		stack_a->size--;
		stack_b->size++;
	}
	write(1, "pb\n", 3);
}
