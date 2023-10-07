/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:56:21 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:23:12 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack **s)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_num;

	if (!s || !(*s)->next)
		return ;
	head = *s;
	next = head->next;
	tmp_num = head->num;
	head->num = next->num;
	next->num = tmp_num;
}

void	sa(t_stack **a, int write)
{
	if (!(*a))
		return ;
	swap(a);
	if (write)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int write)
{
	if (!(*b))
		return ;
	swap(b);
	if (write)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int write)
{
	swap(a);
	swap(b);
	if (write)
		ft_printf("ss\n");
}
