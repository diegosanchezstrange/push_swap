/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:06:54 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/18 13:26:03 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intdup(int i)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = i;
	return (res);
}

int	ft_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if ((*(int *)stack->content) > *((int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
