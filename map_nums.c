/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego </var/mail/diego>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:23:01 by diego             #+#    #+#             */
/*   Updated: 2021/10/12 18:28:44 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_count_map(t_list *stack, int num)
{
	int	*c;

	c = malloc(sizeof(int));
	if (!c)
		return (NULL);
	*c = 1;
	while (stack)
	{
		if (*(int *)stack->content < num)
			*c += 1;
		stack = stack->next;
	}
	return (c);
}

t_list	**ft_lstmap_nums(t_list **stack)
{
	t_list	*aux;
	t_list	**new;
	int		*c;

	new = malloc(sizeof(void *));
	if (stack == NULL || !stack || !new)
		return (NULL);
	aux = *stack;
	*new = NULL;
	while (aux)
	{
		c = ft_count_map(*stack, *(int *)aux->content);
		ft_lstadd_back(new, ft_lstnew(c));
		aux = aux->next;
	}
	return (new);
}
