/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:06:02 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/27 18:32:50 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	if (argc == 1)
		return (0);
	stack_a = ft_calloc(1, sizeof(void *));
	stack_b = ft_calloc(1, sizeof(void *));
	if (!stack_a || !stack_b)
		return (1);
	i = ft_check_params(argc, argv, stack_a);
	if (!i)
	{
		ft_free_stacks(stack_a, stack_b);
		write(1, "Error\n", 6);
		return (2);
	}
	if (i == 3)
		ft_sort_3(stack_a);
	else if (i == 5 || i == 4)
		ft_sort_5(stack_a, stack_b);
	else if (i > 5)
		ft_sort_100(stack_a, stack_b, (ft_lstsize(*stack_a) / 13 ) + 22);
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
