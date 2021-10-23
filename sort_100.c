/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:22:01 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/23 15:59:27 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sort_100(t_list **stack_a, t_list **stack_b, int step)
{
	t_list		**new_a;
	t_position	max;

	if (ft_is_sorted(*stack_a))
		return ;
	new_a = ft_lstmap_nums(stack_a);
	ft_push_b(new_a, stack_b, step);
	while (ft_lstsize(*stack_b) > 0)
	{
		max = ft_get_max(*stack_b);
		if (max.pos < ft_lstsize(*stack_b) / 2)
			ft_rpa(new_a, stack_b, max.pos, ft_rrb);
		else
		{
			max.pos = ft_lstsize(*stack_b) - max.pos;
			ft_rpa(new_a, stack_b, max.pos, ft_rb);
		}
	}
	ft_lstclear(new_a, free);
	free(new_a);
}
