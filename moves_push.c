/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:57 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/09 17:57:49 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*new_first;

	if (*stack_src == NULL)
		return ;
	new_first = (*stack_src)->next;
	ft_lstadd_front(stack_dest, *stack_src);
	*stack_src = new_first;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
