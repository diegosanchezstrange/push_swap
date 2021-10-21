/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:06:22 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/21 19:21:48 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_min(t_list *stack, int *pos)
{
	int	min;

	min = *((int *)stack->content);
	*pos = ft_lstsize(stack);
	while (stack)
	{
		if (*((int *)stack->content) < min)
		{
			min = *((int *)stack->content);
			*pos = ft_lstsize(stack);
		}
		stack = stack->next;
	}
	return (min);
}

void	ft_push_min(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		pos;

	min = ft_get_min(*stack_a, &pos);
	while (*(int *)(*stack_a)->content != min)
	{
		if (pos > 3)
			ft_ra(stack_a);
		else if (pos <= 3)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	ft_push_min(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 4)
		ft_push_min(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
	if (a > b && c > a)
		ft_sa(stack_a);
	else if (a > b && b < c)
		ft_ra(stack_a);
	else if (b > a && b > c && a > c)
		ft_rra(stack_a);
	else if (b > a && b > c && a < c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a > b && b > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}
