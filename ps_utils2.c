/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:03:03 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:53:26 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_min(t_stack *lst)
{
	int	min;

	min = INT_MAX;
	if (!lst)
		error("list shouln't de empty");
	while (lst != NULL)
	{
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

int	stack_max(t_stack *lst)
{
	int	max;

	max = INT_MIN;
	if (!lst)
		error("list shouldn't be empty");
	while (lst != NULL)
	{
		if (lst->num > max)
			max = lst->num;
		lst = lst->next;
	}
	return (max);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_split(char **spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

void	free_split_err(char **spl, t_stack **stack)
{
	free_split(spl);
	free_stack(stack);
	error("Error");
}
