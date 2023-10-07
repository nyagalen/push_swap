/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:36:04 by svydrina          #+#    #+#             */
/*   Updated: 2023/09/23 20:57:11 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **to, t_stack **from)
{
	t_stack	*tmp;
	t_stack	*to_head;
	t_stack	*from_head;

	if (!from)
		return ;
	to_head = *to;
	from_head = *from;
	tmp = from_head;
	from_head = from_head->next;
	*from = from_head;
	if (!to_head)
	{
		to_head = tmp;
		to_head->next = NULL;
		*to = to_head;
	}
	else
	{
		tmp->next = to_head;
		*to = tmp;
	}
}

void	pa(t_stack **a, t_stack **b, int write)
{
	if (!(*b))
		return ;
	push(a, b);
	if (write)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int write)
{
	if (!(*b))
		return ;
	push(a, b);
	if (write)
		ft_printf("pb\n");
}
