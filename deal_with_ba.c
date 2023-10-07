/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:53:18 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:43:51 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_moves_ba(t_stack *min_b, int szb, int sza, t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	assign_min_moves_ba(min_b, szb, sza, moves);
}

void	assign_min_moves_ba(t_stack *b, int szb, int sza, t_moves *moves)
{
	int	rr_cost;
	int	rrr_cost;
	int	rf_rrto;
	int	rrf_rto;
	int	min;

	rr_cost = max_two(b->pos, b->targ_pos);
	rrr_cost = max_two(szb - b->pos, sza - b->targ_pos);
	rf_rrto = b->pos + szb - b->targ_pos;
	rrf_rto = szb - b->pos + b->targ_pos;
	min = min_four(rr_cost, rrr_cost, rf_rrto, rrf_rto);
	if (rr_cost == min)
		assign_rr_ba(b, moves);
	else if (rrr_cost == min)
		assign_rrr_ba(b, szb, sza, moves);
	else if (rf_rrto == min)
		assign_rb_rra(b, sza, moves);
	else
		assign_rrb_ra(b, szb, moves);
}
