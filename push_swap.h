/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:06:07 by dsanchez          #+#    #+#             */
/*   Updated: 2021/10/23 15:59:19 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_position
{
	int	num;
	int	pos;
}	t_position;

void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);

void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);

void		ft_ra(t_list **stack_a);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);

void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);

int			ft_is_sorted(t_list *stack);
int			ft_check_params(int argc, char **argv, t_list **stack_a);
int			*ft_intdup(int i);
t_list		**ft_lstmap_nums(t_list **stack);

t_position	ft_put_next(t_list *stack_a, int max, int size);
t_position	ft_get_max(t_list *stack_a);
void		ft_rpb(t_list **s_a, t_list **s_b, int pos, void (*f)(t_list **));
void		ft_rpa(t_list **s_a, t_list **s_b, int pos, void (*f)(t_list **));
void		ft_push_b(t_list **stack_a, t_list **stack_b, int step);

void		ft_sort_3(t_list **stack_a);
void		ft_sort_5(t_list **stack_a, t_list **stack_b);
void		ft_sort_100(t_list **stack_a, t_list **stack_b, int step);
#endif
