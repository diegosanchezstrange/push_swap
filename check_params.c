/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego </var/mail/diego>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:06:04 by diego             #+#    #+#             */
/*   Updated: 2021/10/21 18:08:03 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_aredigits(char *nptr)
{
	int	sign;
	unsigned int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - 48);
		if ((res > 2147483647 && sign == 1) 
			|| (res > 2147483648 && sign == -1))
				return (0);
		i++;
	}
	if (nptr[i])
		return (0);
	return (res * sign);
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
