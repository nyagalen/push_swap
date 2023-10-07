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

int	ft_atoi(char *str)
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
	if (result < INT_MIN || result > INT_MAX)
		error("Error");
	return ((int)result);
}

t_stack	*stack_split(char **argv)
{
	char	**str;
	t_stack	*a;
	int		i;
	int		num;

	i = 0;
	a = NULL;
	str = ft_split(argv[1], ' ');
	check_nums(str, 0);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		free(str[i]);
		stack_addback(&a, stack_new(num));
		i++;
	}
	free(str);
	return (a);
}

t_stack	*argv_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		num;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = stack_split(argv);
	else
	{
		check_nums(argv, 1);
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			stack_addback(&a, stack_new(num));
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
