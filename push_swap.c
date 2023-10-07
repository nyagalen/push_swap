/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetlana <svetlana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:28:43 by svydrina          #+#    #+#             */
/*   Updated: 2023/10/04 16:28:29 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = argv_stack(argc, argv);
	if (!check_doubles(stack_a))
	{
		free_stack(&stack_a);
		error("Error");
	}
	if (!stack_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
