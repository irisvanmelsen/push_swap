/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:54:58 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// main in which the heads of the stacks are placed at NULL
// the arguments are being parsed by parse_args
// stack.elements_a = total amount of args minus ./push_swap
// then quicksort algorithm is done and everything is freed

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argv, &stack))
		return (error_message(), 0);
	stack.elements_a = argc - 1;
	stack.sort = 0;
	stack.elements_b = 0;
	if (is_sorted(stack.stack_a) == 1)
		return (0);
	quicksort_a(&stack, argc - 1);
	free_lst(stack.stack_a);
	free_lst(stack.stack_b);
	return (EXIT_SUCCESS);
}
