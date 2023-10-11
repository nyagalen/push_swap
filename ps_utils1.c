/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:00:57 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:47:05 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

t_stack	*stack_split(char **argv)
{
	char	**str;
	t_stack	*a;
	int		i;
	long	num;

	i = 0;
	a = NULL;
	str = ft_split(argv[1], ' ');
	if (!check_nums(str, 0))
		free_split_err(str, &a);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num < INT_MIN || num > INT_MAX)
			free_split_err(str, &a);
		stack_addback(&a, stack_new((int)num));
		i++;
	}
	free_split(str);
	return (a);
}

t_stack	*argv_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	long	num;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = stack_split(argv);
	else
	{
		if (!check_nums(argv, 1))
			error("Error");
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			if (num < INT_MIN || num > INT_MAX)
			{
				free_stack(&a);
				error("Error");
			}
			stack_addback(&a, stack_new((int)num));
			i++;
		}
	}
	return (a);
}

int	stack_sorted(t_stack *stack)
{
	if (stack_size(stack) == 1)
		return (1);
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
