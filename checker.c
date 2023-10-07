/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:52:23 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/07 15:00:51 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*do_instructions(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, 0);
	else
		error("Error");
	return (get_next_line(0));
}

static void	read_instructions(t_stack **a, t_stack **b, char *str)
{
	char	*tmp;

	while (str && *str != '\n')
	{
		tmp = str;
		str = do_instructions(a, b, str);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!stack_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (argc < 2)
		return (0);
	a = argv_stack(argc, argv);
	b = NULL;
	if (!check_doubles(a))
	{
		free_stack(&a);
		error("Error");
	}
	str = get_next_line(0);
	if (stack_sorted(a) && !str)
		ft_printf("OK\n");
	else if (!stack_sorted(a) && !str)
		ft_printf("KO\n");
	else
		read_instructions(&a, &b, str);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
