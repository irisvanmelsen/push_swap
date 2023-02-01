/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/01 16:50:43 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!parse_args(argv, &stack_a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	bubblesort(&stack_a);
	print_stack(stack_a);
	if (!find_pivot(stack_a))
		write (1, "Error\n", 6);
	return (EXIT_SUCCESS);
}