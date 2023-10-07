/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:29:31 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:32:38 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_two(int one, int two)
{
	if (one > two)
		return (one);
	return (two);
}

int	min_four(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	if (d <= a && d <= c && d <= b)
		return (d);
	return (-1);
}

int	calc_cost(int f_size, int t_size, int f_pos, int t_pos)
{
	int	rr_cost;
	int	rrr_cost;
	int	rf_rrto;
	int	rrf_rto;

	rr_cost = max_two(f_pos, t_pos);
	rrr_cost = max_two(f_size - f_pos, t_size - t_pos);
	rf_rrto = f_pos + (t_size - t_pos);
	rrf_rto = (f_size - f_pos) + t_pos;
	return (min_four(rr_cost, rrr_cost, rf_rrto, rrf_rto));
}

void	assign_min_moves_ab(t_stack *a, int sza, int szb, t_moves *moves)
{
	int	rr_cost;
	int	rrr_cost;
	int	rf_rrto;
	int	rrf_rto;
	int	min;

	rr_cost = max_two(a->pos, a->targ_pos);
	rrr_cost = max_two(sza - a->pos, szb - a->targ_pos);
	rf_rrto = a->pos + szb - a->targ_pos;
	rrf_rto = sza - a->pos + a->targ_pos;
	min = min_four(rr_cost, rrr_cost, rf_rrto, rrf_rto);
	if (rr_cost == min)
		assign_rr_ab(a, moves);
	else if (rrr_cost == min)
		assign_rrr_ab(a, sza, szb, moves);
	else if (rf_rrto == min)
		assign_ra_rrb(a, szb, moves);
	else
		assign_rra_rb(a, sza, moves);
}

int	min_cost(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->cost < min)
			min = stack->cost;
		stack = stack->next;
	}
	return (min);
}
