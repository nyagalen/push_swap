/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ab_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:04:12 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:42:48 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_two(int one, int two)
{
	if (one < two)
		return (one);
	return (two);
}

void	assign_rr_ab(t_stack *a, t_moves *moves)
{
	int	min;

	min = min_two(a->pos, a->targ_pos);
	moves->rr = min;
	if (a->pos == min)
		moves->rb = a->targ_pos - min;
	else
		moves->ra = a->pos - min;
}

void	assign_rrr_ab(t_stack *a, int sza, int szb, t_moves *moves)
{
	int	moves_a;
	int	moves_b;
	int	min;

	moves_a = sza - a->pos;
	moves_b = szb - a->targ_pos;
	min = min_two(moves_a, moves_b);
	moves->rrr = min;
	if (moves_a == min)
		moves->rrb = moves_b - min;
	else
		moves->rra = moves_a - min;
}

void	assign_ra_rrb(t_stack *a, int szb, t_moves *moves)
{
	int	moves_b;

	moves_b = szb - a->targ_pos;
	moves->ra = a->pos;
	moves->rrb = moves_b;
}

void	assign_rra_rb(t_stack *a, int sza, t_moves *moves)
{
	int	moves_a;

	moves_a = sza - a->pos;
	moves->rra = moves_a;
	moves->rb = a->targ_pos;
}
