/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:27:30 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/05 23:02:01 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_sorted(*stack))
		return ;
	if ((*stack)->num == stack_min(*stack))
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if ((*stack)->num == stack_max(*stack))
	{
		ra(stack, 1);
		if (!stack_sorted(*stack))
			sa(stack, 1);
	}
	else
	{
		if ((*stack)->next->num == stack_max(*stack))
			rra(stack, 1);
		else
			sa(stack, 1);
	}
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_moves *moves)
{
	while (stack_size(*stack_a) > 3 && !stack_sorted(*stack_a))
	{
		update_pos(*stack_a);
		update_pos(*stack_b);
		update_target(*stack_a, *stack_b, 'b');
		update_cost(*stack_a, *stack_b);
		findmin_assign(*stack_a, *stack_b, moves, 'a');
		do_moves(stack_a, stack_b, moves);
		pb(stack_b, stack_a, 1);
	}
}

t_stack	*frame(t_stack **stack_a, t_moves *moves)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack_sorted(*stack_a) && stack_size(*stack_a) > 3)
		pb(&stack_b, stack_a, 1);
	if (!stack_sorted(*stack_a) && stack_size(*stack_a) > 3)
		pb(&stack_b, stack_a, 1);
	if (!stack_sorted(*stack_a) && stack_size(*stack_a) > 3)
		a_to_b(stack_a, &stack_b, moves);
	if (!stack_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**b_to_a(t_stack **stack_b, t_stack **stack_a, t_moves *moves)
{
	int	i;

	while (stack_size(*stack_b) > 0)
	{
		update_pos(*stack_b);
		update_pos(*stack_a);
		update_target(*stack_b, *stack_a, 'a');
		update_cost(*stack_b, *stack_a);
		findmin_assign(*stack_b, *stack_a, moves, 'b');
		do_moves(stack_a, stack_b, moves);
		pa(stack_a, stack_b, 1);
	}
	update_pos(*stack_a);
	i = find_pos_num(*stack_a, stack_min(*stack_a));
	if (i <= stack_size(*stack_a) / 2)
	{
		while ((*stack_a)->num != stack_min(*stack_a))
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->num != stack_min(*stack_a))
			rra(stack_a, 1);
	}
	return (stack_a);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_moves	*moves;

	stack_b = NULL;
	if (stack_size(*stack_a) == 2)
		sa(stack_a, 1);
	else
	{
		moves = malloc(sizeof(t_moves));
		stack_b = frame(stack_a, moves);
		stack_a = b_to_a(&stack_b, stack_a, moves);
		free(moves);
	}
}
