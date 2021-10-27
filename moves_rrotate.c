/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:43:31 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/27 18:32:59 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*aux;
	t_list	*first;

	if (*stack == NULL)
		return ;
	first = *stack;
	while ((*stack)->next)
	{
		aux = *stack;
		*stack = (*stack)->next;
	}
	(*stack)->next = first;
	aux->next = NULL;
}

void	ft_rra(t_list **stack_a)
{
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}
