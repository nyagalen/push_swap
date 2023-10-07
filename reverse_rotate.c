/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:53:11 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:36:12 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	if (stack_size(*stack) < 2)
		return ;
	head = *stack;
	tail = stack_last(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_stack **a, int write)
{
	reverse_rotate(a);
	if (write)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int write)
{
	reverse_rotate(b);
	if (write)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int write)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (write)
		ft_printf("rrr\n");
}
