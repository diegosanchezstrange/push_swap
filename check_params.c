/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego </var/mail/diego>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:06:04 by diego             #+#    #+#             */
/*   Updated: 2021/10/18 13:33:35 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_aredigits(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_is_repeated(t_list *stack, int param)
{
	while (stack)
	{
		if (*(int *)stack->content == param)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_fill_stack(t_list **stack_a, char **params)
{
	int		j;

	j = 0;
	while (*params)
	{
		if (!ft_aredigits(*params))
			return (0);
		if (ft_is_repeated(*stack_a, ft_atoi(*params)))
			return (0);
		ft_lstadd_back(stack_a, ft_lstnew(ft_intdup(ft_atoi(*params))));
		params++;
		j++;
	}
	return (j);
}

int	ft_check_params(int argc, char **argv, t_list **stack_a)
{
	char	**params;
	int		i;
	int		c;
	int		r;

	i = 1;
	c = 0;
	r = 0;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		params = ft_split(argv[i], ' ');
		r = ft_fill_stack(stack_a, params);
		ft_free_split(params);
		if (r == 0)
			return (0);
		c += r;
		i++;
	}
	return (c);
}
