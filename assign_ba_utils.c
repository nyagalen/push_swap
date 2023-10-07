/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ba_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:43:12 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/05 20:18:50 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_tpos_ba(t_stack *to, int from_num)
{
	int	tpos;

	tpos = -1;
	if (from_num < to->num && from_num > stack_last(to)->num)
		tpos = 0;
	else if (from_num > stack_max(to) || from_num < stack_min(to))
		tpos = find_pos_num(to, stack_min(to));
	else
	{
		while (to)
		{
			if (from_num > to->num && from_num < to->next->num)
				return (to->next->pos);
			to = to->next;
		}
	}
	return (tpos);
}

void	assign_rr_ba(t_stack *b, t_moves *moves)
{
	int	min;

	min = min_two(b->pos, b->targ_pos);
	moves->rr = min;
	if (b->pos == min)
		moves->ra = b->targ_pos - min;
	else
		moves->rb = b->pos - min;
}

void	assign_rrr_ba(t_stack *b, int szb, int sza, t_moves *moves)
{
	int	moves_b;
	int	moves_a;
	int	min;

	moves_b = szb - b->pos;
	moves_a = sza - b->targ_pos;
	min = min_two(moves_b, moves_a);
	moves->rrr = min;
	if (moves_b == min)
		moves->rra = moves_a - min;
	else
		moves->rrb = moves_b - min;
}

void	assign_rb_rra(t_stack *b, int sza, t_moves *moves)
{
	int	moves_a;

	moves_a = sza - b->targ_pos;
	moves->rb = b->pos;
	moves->rra = moves_a;
}

void	assign_rrb_ra(t_stack *b, int szb, t_moves *moves)
{
	int	moves_b;

	moves_b = szb - b->pos;
	moves->rrb = moves_b;
	moves->ra = b->targ_pos;
}
