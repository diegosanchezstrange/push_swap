/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:22:01 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/13 12:11:00 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_list(t_list *stack)
{
	printf("---------------------------\n");
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	printf("---------------------------\n");
}

t_position	ft_put_next(t_list *stack_a, int max, int size)
{
	t_position	first;
	t_position	last;
	int	act;

	first.num = -1;
	last.pos = -1;
	while (stack_a)
	{
		act = *(int *)stack_a->content;
		if (first.num == -1 && act <= max)
		{
			first.num = act;
			first.pos = ft_lstsize(stack_a);
		}
		else if (act <= max)
		{
			last.num = act;
			last.pos = ft_lstsize(stack_a);
		}
		stack_a = stack_a->next;
	}
	if (size - first.pos < last.pos || last.pos == -1)
		return (first);
	return (last);
}

t_position ft_get_max(t_list *stack_a)
{
	t_position	max;

	max.num = 0;
	max.pos = 0;
	if (!stack_a)
		return (max);
	while (stack_a)
	{
		if (*(int *)stack_a->content >= max.num)
		{
			max.num = *(int *)stack_a->content;
			max.pos = ft_lstsize(stack_a);
		}
		stack_a = stack_a->next;
	}
	return (max);
}


void	ft_rpb(t_list **stack_a, t_list **stack_b, int pos, void (*f)(t_list **))
{
	while (pos--)
		(*f)(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_rpa(t_list **stack_a, t_list **stack_b, int pos, void (*f)(t_list **))
{
	while (pos--)
		(*f)(stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b, int step)
{
	t_position	pos;
	int			max;
	int			size;
	int			i;

	size = ft_lstsize(*stack_a);
	max = 0;
	while (max < size)
	{
		i = 0;
		max += step;
		while (i < step && *stack_a != NULL)
		{
			pos = ft_put_next(*stack_a, max, ft_lstsize(*stack_a));
			if (pos.pos < ft_lstsize(*stack_a) / 2)
				ft_rpb(stack_a, stack_b, pos.pos , ft_rra);
			else
				ft_rpb(stack_a, stack_b, ft_lstsize(*stack_a) - pos.pos , ft_ra);
			i++;
		}
	}
}

void	ft_sort_100(t_list **stack_a, t_list **stack_b, int step)
{
	t_list		**new_a;
	t_position	max;

	new_a = ft_lstmap_nums(stack_a);
	ft_push_b(new_a, stack_b, step);
	while (ft_lstsize(*stack_b) > 0)
	{
		max = ft_get_max(*stack_b);
		if (max.pos < ft_lstsize(*stack_b) / 2)
			ft_rpa(new_a, stack_b, max.pos , ft_rrb);
		else
			ft_rpa(new_a, stack_b, ft_lstsize(*stack_b) - max.pos , ft_rb);
	}
	ft_lstclear(new_a, free);
	free(new_a);
}
