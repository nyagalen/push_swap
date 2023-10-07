/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetlana <svetlana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:15:49 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/03 19:40:08 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	check_nums(char **argv, int start)
{
	int	c;
	int	i;

	c = start;
	while (argv[c])
	{
		i = 0;
		if (argv[c][i] == 45)
			i++;
		while (argv[c][i])
		{
			if (argv[c][i] < 48 || argv[c][i] > 57)
				error("Error");
			i++;
		}
		c++;
	}
}

int	check_doubles(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num == tmp->num)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
