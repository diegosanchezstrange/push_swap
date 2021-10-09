/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:06:02 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/09 19:21:40 by dsanchez         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	if (argc < 2)
		return (1);
	stack_a = malloc(sizeof(void *));
	stack_b = malloc(sizeof(t_list));
	i = 1;
	if (!stack_a || !stack_b)
		return (2);
	*stack_a = NULL;
	*stack_b = NULL;
	while (i < argc)
	{
		if (!ft_aredigits(argv[i]))
		{
			write(1, "Error\n", 6);
			return (3);
		}
		ft_lstadd_back(stack_a, ft_lstnew(ft_intdup(ft_atoi(argv[i]))));
		i++;
	}
	if (argc == 4)
		ft_sort_3(stack_a);
	else if (argc == 6 || argc == 5)
		ft_sort_5(stack_a, stack_b);
	else if (argc > 6 && argc < 101)
		ft_sort_100(stack_a, stack_b);
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
