#include "push_swap.h"
#include <stdio.h>

int	main()
{
	t_list	**stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	i = 42;
	if (!stack_a || !stack_b)
		return (1);
	*stack_a = ft_lstnew(&i);

	printf("%d", *((int *)(*stack_a)->content));

	return (0);
}
