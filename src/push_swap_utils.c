/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:41 by mbany             #+#    #+#             */
/*   Updated: 2024/11/02 19:37:46 by mbany            ###   ########.fr       */
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
	*nbrs = (int *)malloc(sizeof(int) * (*nbr_nbrs));
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

int		fill_nbrs_array(int ac, char **av, int *nbrs)
{
	int i;
	long nbr;

	i=0;
	if (ac > 2)
	{
		while (i < ac -1)
		{
			if (ft_check_forbidden_char(av[i+1]) == EXIT_FAILURE)
				return (-1);
			nbr = ft_atol(av[i+1]);
			if (ft_check_int_range(nbr) == EXIT_FAILURE)
				return (-1);
			if (nbr == -1 && av[i+1][0] != '-')
				return (-1);
			nbrs[i] = (int)nbr;
			i++;
		}
	}
	else if ( ac == 2)
		split_atol_free(av[1], nbrs);
	else
		ft_error();
	return (0);
}



int		check_duplicates(int *nbr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr[i] == nbr[j])
				return (-1);
			j++;
		}
		i++;		
	}
	return (0);
}

