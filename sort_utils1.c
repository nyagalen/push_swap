/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:13:06 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/05 19:55:03 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		pos++;
		stack = stack->next;
	}
}

int	find_pos_num(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->num == n)
			return (stack->pos);
		stack = stack->next;
	}
	return (-1);
}

int	find_tpos_ab(t_stack *to, int from_num)
{
	int	tpos;

	tpos = -1;
	if (from_num > to->num && from_num < stack_last(to)->num)
		tpos = 0;
	else if (from_num > stack_max(to) || from_num < stack_min(to))
		tpos = find_pos_num(to, stack_max(to));
	else
	{
		while (to)
		{
			if (from_num < to->num && from_num > to->next->num)
				return (to->next->pos);
			to = to->next;
		}
	}
	return (tpos);
}

void	update_target(t_stack *from, t_stack *to, char where_to)
{
	while (from)
	{
		if (where_to == 'b')
			from->targ_pos = find_tpos_ab(to, from->num);
		else
			from->targ_pos = find_tpos_ba(to, from->num);
		from = from->next;
	}
}

void	update_cost(t_stack *from, t_stack *to)
{
	int	f_size;
	int	t_size;
	int	pos;
	int	t_pos;

	f_size = stack_size(from);
	t_size = stack_size(to);
	while (from)
	{
		pos = from->pos;
		t_pos = from->targ_pos;
		from->cost = calc_cost(f_size, t_size, pos, t_pos);
		from = from->next;
	}
}
