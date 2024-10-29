/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michalkcb <michalkcb@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:07 by michalkcb         #+#    #+#             */
/*   Updated: 2024/10/29 19:11:37 by michalkcb        ###   ########.fr       */
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



#endif

