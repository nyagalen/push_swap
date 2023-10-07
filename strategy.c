/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:30:30 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 17:07:21 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_moves_ab(t_stack *min_a, int sza, int szb, t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	assign_min_moves_ab(min_a, sza, szb, moves);
}

void	do_moves(t_stack **a, t_stack **b, t_moves *moves)
{
	while (moves->ra-- > 0)
		ra(a, 1);
	while (moves->rb-- > 0)
		rb(b, 1);
	while (moves->rr-- > 0)
		rr(a, b, 1);
	while (moves->rra-- > 0)
		rra(a, 1);
	while (moves->rrb-- > 0)
		rrb(b, 1);
	while (moves->rrr-- > 0)
		rrr(a, b, 1);
}

void	findmin_assign(t_stack *from, t_stack *to, t_moves *moves, char c)
{
	int	min_cst;
	int	szf;
	int	szt;

	min_cst = min_cost(from);
	szf = stack_size(from);
	szt = stack_size(to);
	while (from)
	{
		if (from->cost == min_cst)
		{
			if (c == 'a')
				assign_moves_ab(from, szf, szt, moves);
			else
				assign_moves_ba(from, szf, szt, moves);
			break ;
		}
		from = from->next;
	}
}
