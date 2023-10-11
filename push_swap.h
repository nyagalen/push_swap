/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetlana <svetlana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:07:17 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/05 20:03:38 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	int				targ_pos;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

void	assign_rr_ab(t_stack *a, t_moves *moves);
void	assign_rrr_ab(t_stack *a, int sza, int szb, t_moves *moves);
void	assign_ra_rrb(t_stack *a, int szb, t_moves *moves);
void	assign_rra_rb(t_stack *a, int sza, t_moves *moves);
void	assign_rr_ba(t_stack *b, t_moves *moves);
void	assign_rrr_ba(t_stack *b, int szb, int sza, t_moves *moves);
void	assign_rb_rra(t_stack *b, int sza, t_moves *moves);
void	assign_rrb_ra(t_stack *b, int szb, t_moves *moves);
int		min_two(int one, int two);
int		max_two(int one, int two);
int		min_four(int a, int b, int c, int d);
int		calc_cost(int f_size, int t_size, int f_pos, int t_pos);
void	assign_min_moves_ab(t_stack *a, int sza, int szb, t_moves *moves);
int		min_cost(t_stack *stack);
void	assign_moves_ba(t_stack *min_b, int szb, int sza, t_moves *moves);
void	assign_min_moves_ba(t_stack *b, int szb, int sza, t_moves *moves);
void	error(char *str);
int		check_nums(char **argv, int start);
int		check_doubles(t_stack *stack);
long	ft_atoi(char *str);
t_stack	*stack_split(char **argv);
t_stack	*argv_stack(int argc, char **argv);
int		stack_sorted(t_stack *stack);
int		stack_min(t_stack *lst);
int		stack_max(t_stack *lst);
void	free_stack(t_stack **stack);
void	pa(t_stack **a, t_stack **b, int write);
void	pb(t_stack **a, t_stack **b, int write);
void	rra(t_stack **a, int write);
void	rrb(t_stack **b, int write);
void	rrr(t_stack **a, t_stack **b, int write);
void	ra(t_stack **a, int write);
void	rb(t_stack **b, int write);
void	rr(t_stack **a, t_stack **b, int write);
void	sort_three(t_stack **stack);
void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_moves *moves);
t_stack	*frame(t_stack **stack_a, t_moves *moves);
t_stack	**b_to_a(t_stack **stack_b, t_stack **stack_a, t_moves *moves);
void	sort_stack(t_stack **stack_a);
void	update_pos(t_stack *stack);
int		find_pos_num(t_stack *stack, int n);
int		find_tpos(t_stack *to, int from_num);
void	update_target(t_stack *from, t_stack *to, char where_to);
void	update_cost(t_stack *from, t_stack *to);
t_stack	*stack_new(int num);
void	stack_addback(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
void	assign_moves_ab(t_stack *min_a, int sza, int szb, t_moves *moves);
void	do_moves(t_stack **a, t_stack **b, t_moves *moves);
void	findmin_assign(t_stack *from, t_stack *to, t_moves *moves, char c);
void	sa(t_stack **a, int write);
void	sb(t_stack **b, int write);
void	ss(t_stack **a, t_stack **b, int write);
void	print_stack(t_stack *stack);
int		find_tpos_ba(t_stack *to, int from_num);
void	free_split(char **spl);
void	free_split_err(char **spl);

#endif
