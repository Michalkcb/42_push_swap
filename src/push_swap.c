/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:53 by mbany             #+#    #+#             */
/*   Updated: 2024/11/03 14:30:03 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
int* str_to_tab(char str[], int* len)
{
    int start = 0;
    int end = 0;
    int* tab = (int*)malloc(strlen(str) * sizeof(int));
    int count = 0;
    //printf("\n\n");
    //printf("asd %s", str);
    int strcount = 0;
    while(*(str + strcount)) {
        if (*(str + strcount) == ' ') {
            tab[count] = atoi(str+start);
            count++;
            start = end +1;
        }

        end++;
        strcount++;
    }

    tab[count] = atoi(str + start);

    tab = (int*)realloc((void*)tab, sizeof(int)*(count+1));

    *len = (count+1);

    return tab;
}

void bubble(int* tab, int len) {
    for(int i = 0; i < len; i++) {
        int temp = tab[i];
        if (tab[i] > tab[i+1]) {
            tab[i] = tab[i+1];
            tab[i+1] = temp;
        }

    }
}
*/
int	init_stack(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	int	*nbrs;
	int	nbr_nbrs;
	int	i;

	init_nbrs_array(ac, av, &nbrs, &nbr_nbrs);
	if (alloc_mem_4_stack(stack_a, stack_b) == -1)
	{
		free(nbrs);
		ft_error();
	}
	i = nbr_nbrs - 1;
	while (i >= 0)
		create_new_node_4_top(*stack_a, nbrs[i--]);
	free(nbrs);
	index_assigmenent(*stack_a);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (init_stack(ac, av, &stack_a, &stack_b) == -1)
		return (-1);
	if (check_sorted_in_stack(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	len = stack_a->size;
	if (stack_a->size == 3)
		sort_3_stack(stack_a);
	else if (stack_a->size < 10)
		sort_4_to_9(stack_a, stack_b);
	else
	{
		sort1(stack_a, stack_b, len);
		sort2(stack_a, stack_b, len);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
