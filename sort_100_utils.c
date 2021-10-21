/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego </var/mail/diego>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:11:09 by diego             #+#    #+#             */
/*   Updated: 2021/10/18 13:12:00 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_position	ft_put_next(t_list *stack_a, int max, int size)
{
	t_position	first;
	t_position	last;
	int			act;

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

t_position	ft_get_max(t_list *stack_a)
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

void	ft_rpb(t_list **s_a, t_list **s_b, int pos, void (*f)(t_list **))
{
	while (pos--)
		(*f)(s_a);
	ft_pb(s_a, s_b);
}

void	ft_rpa(t_list **s_a, t_list **s_b, int pos, void (*f)(t_list **))
{
	while (pos--)
		(*f)(s_b);
	ft_pa(s_a, s_b);
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
				ft_rpb(stack_a, stack_b, pos.pos, ft_rra);
			else
				ft_rpb(stack_a, stack_b, ft_lstsize(*stack_a) - pos.pos, ft_ra);
			i++;
		}
	}
}
