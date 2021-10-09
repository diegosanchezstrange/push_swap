/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:06:02 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/09 21:26:33 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	ft_aredigits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	*ft_intdup(int i)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = i;
	return (res);
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

int	ft_check_params(int argc, char **argv, t_list **stack_a)
{
	char	**params;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		params = ft_split(argv[i], ' ');
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
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	stack_a = malloc(sizeof(void *));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		return (2);
	*stack_a = NULL;
	*stack_b = NULL;
	i = ft_check_params(argc, argv, stack_a);
	if (i == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (i == 3)
		ft_sort_3(stack_a);
	else if (i == 5 || i == 4)
		ft_sort_5(stack_a, stack_b);
	//else if (argc > 6 && argc < 101)
		//ft_sort_100(stack_a, stack_b);
	printf("--------------------\n");
	while (*stack_a)
	{
		printf("content : %d\n", *(int *)(*stack_a)->content);
		*stack_a = (*stack_a)->next;
	}
	printf("--------------------\n");
	while (*stack_b)
	{
		printf("content : %d\n", *(int *)(*stack_b)->content);
		*stack_b = (*stack_b)->next;
	}
	printf("--------------------\n");
	return (0);
}
