/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:28 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:48:29 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (stack_size(*stack) < 2)
		return ;
	head = *stack;
	tail = stack_last(*stack);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_stack **a, int write)
{
	rotate(a);
	if (write)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int write)
{
	rotate (b);
	if (write)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int write)
{
	rotate(a);
	rotate(b);
	if (write)
		ft_printf("rr\n");
}
